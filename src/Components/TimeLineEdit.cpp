#include <Chronometer/Components/TimeLineEdit.h>

TimeLineEdit::TimeLineEdit(QString const& object_name)
    : styleSheetAvailable(false)
    , wheelDeltaRemainder(0)
{
    setObjectName(object_name);
    setFrame(false);
    setMaxLength(2);
    setAlignment(Qt::AlignCenter);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFont(QFont({ "Serif", "DejaVu" }, 24, 24, true));
    setMouseTracking(true);

    setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
    setText("00");

    defaultStyleSheet = styleSheet();

    connect(&backgroundBlink, &QTimer::timeout, this, [this] {
        if (!isReadOnly()) {
            if (styleSheetAvailable) {
                setStyleSheet("background-color: black; color: white");
                styleSheetAvailable = false;
            } else {
                setStyleSheet(defaultStyleSheet);
                styleSheetAvailable = true;
            }
        }
    });
}

void TimeLineEdit::focusInEvent(QFocusEvent* event)
{
    QLineEdit::focusInEvent(event);
    enableBlinking();
}

void TimeLineEdit::focusOutEvent(QFocusEvent* event)
{
    QLineEdit::focusOutEvent(event);
    disableBlinking();
}

bool TimeLineEdit::event(QEvent* event)
{
    if (QEvent::Enter == event->type()) {
        enableBlinking();
    } else if (QEvent::Leave == event->type()) {
        disableBlinking();
    } else if (QEvent::KeyPress == event->type()) {
        auto const key = dynamic_cast<QKeyEvent*>(event);
        if (nullptr != key && !isReadOnly()) {
            if (Qt::Key_Up == key->key()) {
                addStep(1);
            } else if (Qt::Key_Down == key->key()) {
                addStep(-1);
            }
        }
    }

    return QLineEdit::event(event);
}

void TimeLineEdit::wheelEvent(QWheelEvent* event)
{
    QLineEdit::wheelEvent(event);

    if (!isReadOnly()) {
        wheelDeltaRemainder += event->angleDelta().y();
        int const steps = wheelDeltaRemainder / 120;
        wheelDeltaRemainder -= steps * 120;
        addStep(steps);
    }
}

void TimeLineEdit::addStep(int const step)
{
    bool isOkay = false;
    auto const currentValue = text().toInt(&isOkay);
    if (isOkay && 0 <= (currentValue + step)) {
        setText(QString::number(currentValue + step));
    }
}

void TimeLineEdit::enableBlinking()
{
    if (!isReadOnly()) {
        setFrame(true);
        styleSheetAvailable = false;
        backgroundBlink.start(500);
    }
}

void TimeLineEdit::disableBlinking()
{
    setFrame(false);
    backgroundBlink.stop();
    setStyleSheet(defaultStyleSheet);
    styleSheetAvailable = true;
}
