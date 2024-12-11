#ifndef SETUPVIEW_H
#define SETUPVIEW_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>

class SetupView : public QWidget {
    Q_OBJECT

public:
    explicit SetupView(QWidget* parent = nullptr);

signals:
    void configurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo);
};

#endif // SETUPVIEW_H
