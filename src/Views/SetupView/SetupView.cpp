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
    SetupView(QWidget* parent = nullptr) : QWidget(parent) {
        setWindowTitle("Paramètres de configuration");
        setFixedSize(400, 300);

        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        QFormLayout* formLayout = new QFormLayout();

        // Champs de configuration
        QSpinBox* timeInput = new QSpinBox();
        timeInput->setRange(1, 240); // Temps en minutes (1 à 240)
        timeInput->setSuffix(" minutes");
        formLayout->addRow("Temps (en minutes) :", timeInput);

        QSpinBox* clientsInput = new QSpinBox();
        clientsInput->setRange(1, 100); // Nombre de clients (1 à 100)
        formLayout->addRow("Nombre de clients :", clientsInput);

        QComboBox* modeInput = new QComboBox();
        modeInput->addItems({"Standard", "Rapide", "Personnalisé"});
        formLayout->addRow("Mode d'opération :", modeInput);

        QLineEdit* additionalInfoInput = new QLineEdit();
        additionalInfoInput->setPlaceholderText("Informations supplémentaires (facultatif)");
        formLayout->addRow("Informations supplémentaires :", additionalInfoInput);

        mainLayout->addLayout(formLayout);

        // Boutons
        QHBoxLayout* buttonLayout = new QHBoxLayout();
        QPushButton* confirmButton = new QPushButton("Valider");
        QPushButton* cancelButton = new QPushButton("Annuler");

        buttonLayout->addWidget(confirmButton);
        buttonLayout->addWidget(cancelButton);

        mainLayout->addLayout(buttonLayout);

        // Connexions des boutons
        connect(confirmButton, &QPushButton::clicked, this, [=]() {
            int time = timeInput->value();
            int clients = clientsInput->value();
            QString mode = modeInput->currentText();
            QString additionalInfo = additionalInfoInput->text();

            if (time <= 0 || clients <= 0) {
                QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
                return;
            }

            QMessageBox::information(this, "Configuration validée",
                                     QString("Temps : %1 minutes\n"
                                             "Nombre de clients : %2\n"
                                             "Mode : %3\n"
                                             "Informations supplémentaires : %4")
                                         .arg(time)
                                         .arg(clients)
                                         .arg(mode)
                                         .arg(additionalInfo.isEmpty() ? "Aucune" : additionalInfo));

            emit configurationValidated(time, clients, mode, additionalInfo);
            close();
        });

        connect(cancelButton, &QPushButton::clicked, this, &QWidget::close);
    }

signals:
    void configurationValidated(int time, int clients, const QString& mode, const QString& additionalInfo);
};
