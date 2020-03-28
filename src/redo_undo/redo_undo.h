#pragma once

#include <QtWidgets/QWidget>
#include "ui_redo_undo.h"
#include <QUndoStack>

class redo_undo : public QWidget {
    Q_OBJECT

public:
    redo_undo(QWidget* parent = Q_NULLPTR);

private:
    Ui::redo_undoClass ui;

    QString* m_document;
    QUndoStack* m_stack;
private slots:
    void save_data();

};
