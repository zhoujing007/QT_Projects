#pragma once
#include<QUndoCommand>

//²åÈë×Ö·û²Ù×÷
class InsertChars : public QUndoCommand {
public:
    InsertChars(int index, const QString& chars, QString* document)
        : QUndoCommand("Insert characters") {
        m_index = index;
        m_chars = chars;
        m_document = document;
    }

    virtual void redo() {
        m_document->insert(m_index, m_chars);
    }

    virtual void undo() {
        m_document->remove(m_index, m_chars.length());
    }

private:
    int m_index;
    QString m_chars;
    QString* m_document;
};

//É¾³ý×Ö·û²Ù×÷
class RemoveChars : public QUndoCommand {
public:
    RemoveChars(int index, int count, QString* document)
        : QUndoCommand("Remove characters") {
        m_index = index;
        m_count = count;
        m_document = document;
    }

    virtual void redo() {
        m_removedChars = m_document->mid(m_index, m_count);
        m_document->remove(m_index, m_count);
    }

    virtual void undo() {
        m_document->insert(m_index, m_removedChars);
    }

private:
    int m_index, m_count;
    QString m_removedChars;
    QString* m_document;
};