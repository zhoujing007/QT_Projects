/****************************************************************************
** Meta object code from reading C++ file 'ffmpeg_test.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ffmpeg_test.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ffmpeg_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ffmpeg_test_t {
    QByteArrayData data[14];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ffmpeg_test_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ffmpeg_test_t qt_meta_stringdata_ffmpeg_test = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ffmpeg_test"
QT_MOC_LITERAL(1, 12, 12), // "start_record"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "close_record"
QT_MOC_LITERAL(4, 39, 16), // "slot_open_camera"
QT_MOC_LITERAL(5, 56, 17), // "slot_close_camera"
QT_MOC_LITERAL(6, 74, 12), // "vedio_player"
QT_MOC_LITERAL(7, 87, 11), // "camera_data"
QT_MOC_LITERAL(8, 99, 6), // "uchar*"
QT_MOC_LITERAL(9, 106, 4), // "data"
QT_MOC_LITERAL(10, 111, 5), // "width"
QT_MOC_LITERAL(11, 117, 6), // "height"
QT_MOC_LITERAL(12, 124, 10), // "show_image"
QT_MOC_LITERAL(13, 135, 3) // "pix"

    },
    "ffmpeg_test\0start_record\0\0close_record\0"
    "slot_open_camera\0slot_close_camera\0"
    "vedio_player\0camera_data\0uchar*\0data\0"
    "width\0height\0show_image\0pix"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ffmpeg_test[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    3,   54,    2, 0x08 /* Private */,
      12,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::QPixmap,   13,

       0        // eod
};

void ffmpeg_test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ffmpeg_test *_t = static_cast<ffmpeg_test *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start_record(); break;
        case 1: _t->close_record(); break;
        case 2: _t->slot_open_camera(); break;
        case 3: _t->slot_close_camera(); break;
        case 4: _t->vedio_player(); break;
        case 5: _t->camera_data((*reinterpret_cast< uchar*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 6: _t->show_image((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ffmpeg_test::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ffmpeg_test.data,
      qt_meta_data_ffmpeg_test,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ffmpeg_test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ffmpeg_test::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ffmpeg_test.stringdata0))
        return static_cast<void*>(const_cast< ffmpeg_test*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ffmpeg_test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
