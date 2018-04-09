/****************************************************************************
** Meta object code from reading C++ file 'SelectJoueur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SelectJoueur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SelectJoueur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SelectJoueur_t {
    QByteArrayData data[9];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectJoueur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectJoueur_t qt_meta_stringdata_SelectJoueur = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SelectJoueur"
QT_MOC_LITERAL(1, 13, 18), // "btnAnnuler_Clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 18), // "btnChoisir_Clicked"
QT_MOC_LITERAL(4, 52, 19), // "btnModifier_Clicked"
QT_MOC_LITERAL(5, 72, 20), // "btnSupprimer_Clicked"
QT_MOC_LITERAL(6, 93, 12), // "joueurChoisi"
QT_MOC_LITERAL(7, 106, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 123, 4) // "item"

    },
    "SelectJoueur\0btnAnnuler_Clicked\0\0"
    "btnChoisir_Clicked\0btnModifier_Clicked\0"
    "btnSupprimer_Clicked\0joueurChoisi\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectJoueur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void SelectJoueur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectJoueur *_t = static_cast<SelectJoueur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->btnAnnuler_Clicked(); break;
        case 1: _t->btnChoisir_Clicked(); break;
        case 2: _t->btnModifier_Clicked(); break;
        case 3: _t->btnSupprimer_Clicked(); break;
        case 4: _t->joueurChoisi((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SelectJoueur::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectJoueur.data,
      qt_meta_data_SelectJoueur,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SelectJoueur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectJoueur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SelectJoueur.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SelectJoueur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
