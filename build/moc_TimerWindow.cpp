/****************************************************************************
** Meta object code from reading C++ file 'TimerWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/headers/TimerWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimerWindow_t {
    QByteArrayData data[8];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimerWindow_t qt_meta_stringdata_TimerWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TimerWindow"
QT_MOC_LITERAL(1, 12, 17), // "handleStartButton"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "handleResetButton"
QT_MOC_LITERAL(4, 49, 19), // "setFontSizeForItems"
QT_MOC_LITERAL(5, 69, 11), // "timeElapsed"
QT_MOC_LITERAL(6, 81, 9), // "remaining"
QT_MOC_LITERAL(7, 91, 12) // "timerTimeout"

    },
    "TimerWindow\0handleStartButton\0\0"
    "handleResetButton\0setFontSizeForItems\0"
    "timeElapsed\0remaining\0timerTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimerWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,    6,
    QMetaType::Void,

       0        // eod
};

void TimerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TimerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleStartButton(); break;
        case 1: _t->handleResetButton(); break;
        case 2: _t->setFontSizeForItems(); break;
        case 3: _t->timeElapsed((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 4: _t->timerTimeout(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TimerWindow::staticMetaObject = { {
    &TimerObserver::staticMetaObject,
    qt_meta_stringdata_TimerWindow.data,
    qt_meta_data_TimerWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TimerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimerWindow.stringdata0))
        return static_cast<void*>(this);
    return TimerObserver::qt_metacast(_clname);
}

int TimerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TimerObserver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
