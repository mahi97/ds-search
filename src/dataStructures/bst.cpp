#include "dataStructures/bst.h"

BST::BST() : Tree(){
    root = NULL;
    name = "BST";
}

void BST::insert(Data* _data) {
    insert(_data, root);
}

void BST::insert(Data *_data, BSTNode*& _node) {
    if (_node == NULL) {
        _node = makeNode(_data);
    } else if (_data->key.toLower() > _node->key_) {
        insert(_data, _node->rc);
    } else if (_data->key.toLower() < _node->key_) {
        insert(_data, _node->lc);
    } else {
        _node->values.insert(_data);
    }
}

BSTNode* BST::makeNode(Data *_data) {
    BSTNode* node = new BSTNode();
    node->key_ = _data->key.toLower();
    node->values.insert(_data);
    size++;
    qDebug() << size << node->key_;
    return node;
}

void BST::search(QString _word, LinkedList &_list, BSTNode *_node) {
    if (_node == NULL) return;
    if (_word == _node->key_) {
        _list = _node->values;
        return;
    } else if (_word < _node->key_) {
        search(_word, _list, _node->lc);
    } else {
        search(_word, _list, _node->rc);
    }
}
QStringList BST::show() {
    wordsCount = 0;
    QStringList tlist;
    return show(root, tlist);
}

LinkedList BST::search(QString _word) {
    LinkedList list;
    search(_word, list, root);
    return list;
}

QStringList BST::show(BSTNode* _node, QStringList& _list) {
    if (_node == NULL) return _list;
    QString tStr;
    QString files;
    wordsCount++;
    show(_node->lc, _list);

    QStringList buffer;
    Q_FOREACH(Data* data, _node->values.toQList()) {
        if (!buffer.contains(data->file)) {
            files.append(data->file);
            files.append(", ");
            buffer.append(data->file);
        }
    }
    files.chop(1);
    tStr = QString ("|%1 -> ").arg(_node->key_) + files;
    _list.append(tStr);
    qDebug() << _node->key_ << _node->values.size();

    show(_node->rc, _list);
    return _list;
}
