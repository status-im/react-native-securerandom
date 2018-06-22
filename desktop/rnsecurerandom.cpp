/**
 * Copyright (C) 2016, Canonical Ltd.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 * Author: Justin McPherson <justin.mcpherson@canonical.com>
 *
 */

#include <memory>

#include "bridge.h"
#include "rnsecurerandom.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
#include <QMap>

namespace {
struct RegisterQMLMetaType {
    RegisterQMLMetaType() {
        qRegisterMetaType<RNSecureRandom*>();
    }
} registerMetaType;
} // namespace

class RNSecureRandomPrivate {
public:

    Bridge* bridge = nullptr;
};

RNSecureRandom::RNSecureRandom(QObject* parent) : QObject(parent), d_ptr(new RNSecureRandomPrivate) {}

RNSecureRandom::~RNSecureRandom() {}

void RNSecureRandom::generateSecureRandomAsBase64(int size,
                                                  const ModuleInterface::ListArgumentBlock &resolve,
                                                  const ModuleInterface::ListArgumentBlock &reject) {
    Q_D(RNSecureRandom);

    qDebug()<<"invoked RNSecureRandom::generateSecureRandomAsBase64";

    QByteArray randomString;
    qsrand(QDateTime::currentDateTime().currentMSecsSinceEpoch());
    while (randomString.size() < size) {
        randomString.push_back(qrand());
    }
    QString result = randomString.toBase64();

    qDebug()<<"RNSecureRandom::generateSecureRandomAsBase64 result: "<<result;

    resolve(d->bridge, QVariantList{QVariant{result}});

}

QString RNSecureRandom::moduleName() {
    return "RNSecureRandom";
}

QList<ModuleMethod*> RNSecureRandom::methodsToExport() {
    return QList<ModuleMethod*>{};
}

QVariantMap RNSecureRandom::constantsToExport() {
    return QVariantMap{};
}

void RNSecureRandom::setBridge(Bridge* bridge) {
    Q_D(RNSecureRandom);
    d->bridge = bridge;
}
