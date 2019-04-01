﻿#include "Element.h"
#include <QtDebug>


Element::~Element() {

}

void Element::setElementId(const QString &id) {
    elementId = id;
}

QString Element::getElementId() const {
    return elementId;
}

QString Element::getInternalElementType() const {

    return internalElementType;
}

void Element::setElementWidth(int width) {
    elementWidth = width;
}

int Element::getElementWidth() const {
    return elementWidth;
}

void Element::setElementHeight(int height) {
    elementHeight = height;
}

int Element::getElementHeight() const {
    return elementHeight;
}

void Element::setElementXPos(int xpos) {
    elementXPos = xpos;
    setX(elementXPos);
}

int Element::getElementXPos() const {
    return elementXPos;
}

void Element::setElementYPos(int ypos) {
    elementYPos = ypos;
    setY(elementYPos);
}

int Element::getElementYPos() const {
    return elementYPos;
}

void Element::setGraphPageLink(const QString &link) {
    graphPageLink = link;
}

QString Element::getGraphPageLink() const {
    return graphPageLink;
}

void Element::setElementZValue(int zval) {
    elementZValue = zval;
    setZValue(elementZValue);
}

int Element::getElementZValue() const {
    return elementZValue;
}

void Element::moveTo(int x, int y) {

    elementXPos = elementXPos + x;
    elementYPos = elementYPos + y;

    setPos(elementXPos,elementYPos);
}

void Element::setAngle(qreal angle_) {

    QTransform transform;
    transform.rotate(angle_);
    elemAngle = angle_;
    setTransform(transform);
}

qreal Element::angle() const {
    return elemAngle;
}

void Element::init() {

    setFlags(QGraphicsItem::ItemIsSelectable |
             QGraphicsItem::ItemIsMovable |
             QGraphicsItem::ItemIsFocusable);
    setAcceptHoverEvents(true);

    resizing = false;

    elementWidth = 70;
    elementHeight = 70;
    elementZValue = zValue();
    backgroundColor = QColor(Qt::blue);
    signBackgroundColor = QColor(Qt::black);
    borderWidth = 2;
    borderColor = QColor(Qt::black);
    elementText = trUtf8("文本");
    fontSize = 10;

    elemAngle = 0;
    rotationCount = 0;

    setSelected(true);

    rd = RdNone;
}

void Element::setBlocked(bool blocked) {

    setFlag(QGraphicsItem::ItemIsMovable,!blocked);
}

void Element::addNodePoint() {
}

void Element::removeNodePoint() {
}

/**
 * @brief Element::setProjectPath
 * @details 设置工程路径
 * @param path 工程路径
 */
void Element::setProjectPath(const QString &path) {
    if(strProjectPath_ != path)
        strProjectPath_ = path;
}


/**
 * @brief Element::getProjectPath
 * @details 获取工程路径
 * @return 工程路径
 */
QString Element::getProjectPath() const {
    return strProjectPath_;
}
