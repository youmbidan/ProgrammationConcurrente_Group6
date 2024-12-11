#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "SetupView.h"


SetupView::SetupView(QWidget* parent) : QWidget(parent) {
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

   QString styleSheet = R"(
    QWidget {
        background-color: #2e2e2e;
        font-family: 'Arial', sans-serif;
        color: white;
    }

    QLabel {
        font-size: 14px;
        color: #b0b0b0;
    }

    QLineEdit, QSpinBox, QComboBox {
        background-color: #444444;
        border: 1px solid #777777;
        color: white;
        border-radius: 5px;
        padding: 5px;
        font-size: 14px;
    }

    QSpinBox::up-button, QSpinBox::down-button {
        background-color: #666666;
        border: none;
        height: 10px;
        width: 10px;
    }

    QComboBox {
        background-color: #444444;
        border: 1px solid #777777;
        border-radius: 5px;
    }

    QPushButton {
        background-color: #AED6F1;
        color: white;
        border: 2px solid #2874A6;
        border-radius: 5px;
        padding: 10px;
        font-size: 16px;
        font-weight: bold;
        min-width: 120px;
    }

    QPushButton:hover {
        background-color: #2874A6;
    }

    QPushButton:pressed {
        background-color: #388e3c;
    }

    QHBoxLayout {
        margin-top: 20px;
        justify-content: center;
    }

    QFormLayout {
        margin: 0;
        padding: 20px;
    }

    QSpinBox, QComboBox {
        padding-left: 10px;
    }

    QLineEdit {
        padding-left: 10px;
    }

    QWidget#SetupView {
        border-radius: 15px;
    }
)";

this->setStyleSheet(styleSheet);


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
