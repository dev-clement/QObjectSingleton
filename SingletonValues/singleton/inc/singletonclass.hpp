#ifndef SINGLETONCLASS_HPP
#define SINGLETONCLASS_HPP

#include <QTimer>
#include <QObject>
#include <QJSEngine>
#include <QQmlEngine>

class SingletonClass : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(int someProperty READ someProperty WRITE setSomeProperty NOTIFY somePropertyChanged)

public:
    explicit SingletonClass(QObject *po_parent = nullptr);
    static QObject *singletonProvider(QQmlEngine *po_engine, QJSEngine *po_jsEngine);
    int someProperty() const;
    void setSomeProperty(int i_someProperty);

signals:
    void somePropertyChanged(int i_someProperty);

private:
    QTimer *_po_timer;
    int _i_someProperty;
};

#endif // SINGLETONCLASS_HPP
