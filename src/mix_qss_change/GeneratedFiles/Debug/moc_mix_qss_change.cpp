/****************************************************************************
** Meta object code from reading C++ file 'mix_qss_change.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mix_qss_change.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mix_qss_change.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mix_qss_change_t {
    QByteArrayData data[5];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mix_qss_change_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mix_qss_change_t qt_meta_stringdata_mix_qss_change = {
    {
QT_MOC_LITERAL(0, 0, 14), // "mix_qss_change"
QT_MOC_LITERAL(1, 15, 10), // "change_qss"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "cur_file"
QT_MOC_LITERAL(4, 36, 11) // "mouse_click"

    },
    "mix_qss_change\0change_qss\0\0cur_file\0"
    "mouse_click"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mix_qss_change[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void mix_qss_change::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mix_qss_change *_t = static_cast<mix_qss_change *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change_qss((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->mouse_click(); break;
        default: ;
        }
    }
}

const QMetaObject mix_qss_change::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mix_qss_change.data,
      qt_meta_data_mix_qss_change,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mix_qss_change::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mix_qss_change::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mix_qss_change.stringdata0))
        return static_cast<void*>(const_cast< mix_qss_change*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mix_qss_change::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
