/****************************************************************************
** Meta object code from reading C++ file 'setmap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/ui_pkg/include/ui_pkg/setmap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setmap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SetMap_t {
    QByteArrayData data[10];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetMap_t qt_meta_stringdata_SetMap = {
    {
QT_MOC_LITERAL(0, 0, 6), // "SetMap"
QT_MOC_LITERAL(1, 7, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "on_up_clicked"
QT_MOC_LITERAL(4, 40, 15), // "on_down_clicked"
QT_MOC_LITERAL(5, 56, 15), // "on_left_clicked"
QT_MOC_LITERAL(6, 72, 16), // "on_right_clicked"
QT_MOC_LITERAL(7, 89, 15), // "on_stop_clicked"
QT_MOC_LITERAL(8, 105, 16), // "on_begin_clicked"
QT_MOC_LITERAL(9, 122, 17) // "on_finish_clicked"

    },
    "SetMap\0on_cancel_clicked\0\0on_up_clicked\0"
    "on_down_clicked\0on_left_clicked\0"
    "on_right_clicked\0on_stop_clicked\0"
    "on_begin_clicked\0on_finish_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetMap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SetMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetMap *_t = static_cast<SetMap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cancel_clicked(); break;
        case 1: _t->on_up_clicked(); break;
        case 2: _t->on_down_clicked(); break;
        case 3: _t->on_left_clicked(); break;
        case 4: _t->on_right_clicked(); break;
        case 5: _t->on_stop_clicked(); break;
        case 6: _t->on_begin_clicked(); break;
        case 7: _t->on_finish_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SetMap::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SetMap.data,
      qt_meta_data_SetMap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SetMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetMap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SetMap.stringdata0))
        return static_cast<void*>(const_cast< SetMap*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SetMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
