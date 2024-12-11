#ifndef SETUPVIEW_H
#define SETUPVIEW_H

#include <QWidget>

class SetupView : public QWidget {
    Q_OBJECT

public:
    explicit SetupView(QWidget* parent = nullptr);

signals:
    void configurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo);
};

#endif // SETUPVIEW_H
