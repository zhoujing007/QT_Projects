/****************************************************************************
** Meta object code from reading C++ file 'CmPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CmPlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CmPlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CmPlayer_t {
    QByteArrayData data[15];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CmPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CmPlayer_t qt_meta_stringdata_CmPlayer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CmPlayer"
QT_MOC_LITERAL(1, 9, 9), // "video_pos"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 16), // "video_start_play"
QT_MOC_LITERAL(4, 37, 19), // "sig_vediofromchange"
QT_MOC_LITERAL(5, 57, 9), // "openLocal"
QT_MOC_LITERAL(6, 67, 7), // "openUrl"
QT_MOC_LITERAL(7, 75, 15), // "play_img_change"
QT_MOC_LITERAL(8, 91, 15), // "control_clicked"
QT_MOC_LITERAL(9, 107, 21), // "slider_volume_changed"
QT_MOC_LITERAL(10, 129, 12), // "volume_value"
QT_MOC_LITERAL(11, 142, 14), // "play_call_back"
QT_MOC_LITERAL(12, 157, 11), // "state_check"
QT_MOC_LITERAL(13, 169, 28), // "on_pushButton_volume_clicked"
QT_MOC_LITERAL(14, 198, 17) // "play_state_change"

    },
    "CmPlayer\0video_pos\0\0video_start_play\0"
    "sig_vediofromchange\0openLocal\0openUrl\0"
    "play_img_change\0control_clicked\0"
    "slider_volume_changed\0volume_value\0"
    "play_call_back\0state_check\0"
    "on_pushButton_volume_clicked\0"
    "play_state_change"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CmPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,
       4,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   79,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    1,   83,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CmPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CmPlayer *_t = static_cast<CmPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->video_pos((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->video_start_play(); break;
        case 2: _t->sig_vediofromchange(); break;
        case 3: _t->openLocal(); break;
        case 4: _t->openUrl(); break;
        case 5: _t->play_img_change(); break;
        case 6: _t->control_clicked(); break;
        case 7: _t->slider_volume_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->play_call_back(); break;
        case 9: _t->state_check(); break;
        case 10: _t->on_pushButton_volume_clicked(); break;
        case 11: _t->play_state_change(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CmPlayer::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CmPlayer::video_pos)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CmPlayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CmPlayer::video_start_play)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CmPlayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CmPlayer::sig_vediofromchange)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CmPlayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CmPlayer.data,
      qt_meta_data_CmPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CmPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CmPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CmPlayer.stringdata0))
        return static_cast<void*>(const_cast< CmPlayer*>(this));
    if (!strcmp(_clname, "VlcVideoDelegate"))
        return static_cast< VlcVideoDelegate*>(const_cast< CmPlayer*>(this));
    return QWidget::qt_metacast(_clname);
}

int CmPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CmPlayer::video_pos(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CmPlayer::video_start_play()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CmPlayer::sig_vediofromchange()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
