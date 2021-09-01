#ifndef CHRONOMETER_TIMELINEEDIT_H
#define CHRONOMETER_TIMELINEEDIT_H

#include <QEvent>
#include <QKeyEvent>
#include <QLineEdit>
#include <QMouseEvent>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QString>
#include <QTimer>
#include <QWheelEvent>

/*!
 * \brief The TimeLineEdit class is a custom QLineEdit for
 * reading two digits unsigned number from user.
 *
 * \note The TimeLineEdit doesn't support the QLineEdit constructors
 */
class TimeLineEdit final : public QLineEdit {
private:
    QString defaultStyleSheet; /*!< Used for reseting default widget stylesheet */
    QTimer backgroundBlink;    /*!< Changes the widget stylesheet on every 500ms */
    bool styleSheetAvailable;  /*!< Determines if we already have the custom stylesheet */
    int wheelDeltaRemainder;   /*!< Used for calculating the step using the wheel event y angle */

public:
    explicit TimeLineEdit(QString const& object_name);

protected:
    /*!
     * \brief Enables blinking effect on focus.
     * \param event
     * \note Works only if isReadOnly() == false.
     */
    void focusInEvent(QFocusEvent* event) override;

    /*!
     * \brief Disable blinking effect on losing focus.
     * \param event
     * \note Works only if isReadOnly() == false.
     */
    void focusOutEvent(QFocusEvent* event) override;

    /*!
     * \brief Takes care of mouse hover/loave and
     * Up/Down arrow keys to increase/decrease
     * the field value.
     * \param event
     * \note Works only if isReadOnly() == false
     */
    bool event(QEvent* event) override;

    /*!
     * \brief Changes the field value according to
     * the mouse wheel angle.
     * \param event
     * \note Works only if isReadOnly() == false
     * \note This doesn't work on Mac OS if
     * the Shift key is pressed on the wheel event,
     * because Mac OS will change the orientation on
     * pressing and holding the Shift key while scrolling.
     */
    void wheelEvent(QWheelEvent* event) override;

private:
    /*!
     * \brief Adds \p step to the current value if is valid.
     * \param step
     * \note A valid value will satisfy these requirements:
     *     - 0 <= value
     *     - [0-9]
     */
    void addStep(int const step);

    /*!
     * \brief Enables the blinking effect if isReadOnly() == false
     */
    void enableBlinking();

    /*!
     * \brief Disable the blinking effect
     */
    void disableBlinking();
};

#endif // CHRONOMETER_TIMELINEEDIT_H
