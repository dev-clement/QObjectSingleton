#include "singletonclass.hpp"

SingletonClass::SingletonClass(QObject *po_parent)
    : QObject{po_parent}
    , _po_timer{ new QTimer{this} }
    , _i_someProperty{ 0 } {
    qDebug() << "Singleton instance created !";
    connect(_po_timer, &QTimer::timeout, this, [=](){
        setSomeProperty(_i_someProperty + 2);
    });
    _po_timer->start(1000);
}

QObject *SingletonClass::singletonProvider(QQmlEngine *po_engine, QJSEngine *po_jsEngine) {
    Q_UNUSED(po_engine);
    Q_UNUSED(po_jsEngine);
    SingletonClass *po_singletonClass = new SingletonClass{};
    return po_singletonClass;
}

int SingletonClass::someProperty() const {
    return _i_someProperty;
}

void SingletonClass::setSomeProperty(int i_someProperty) {
    if (_i_someProperty == i_someProperty)
        return;
    _i_someProperty = i_someProperty;
    emit somePropertyChanged(_i_someProperty);
}
