
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

#ifndef RNSECURERANDOM_H
#define RNSECURERANDOM_H

#include <QUrl>

#include "moduleinterface.h"

class RNSecureRandomPrivate;
class RNSecureRandom : public QObject, public ModuleInterface {
    Q_OBJECT

    Q_INTERFACES(ModuleInterface)

    Q_DECLARE_PRIVATE(RNSecureRandom)

public:

    Q_INVOKABLE RNSecureRandom(QObject* parent = 0);
    ~RNSecureRandom();

    Q_INVOKABLE REACT_PROMISE void generateSecureRandomAsBase64(int size,
                                                                const ModuleInterface::ListArgumentBlock &resolve,
                                                                const ModuleInterface::ListArgumentBlock &reject);
    virtual QString moduleName() override;
    virtual QList<ModuleMethod*> methodsToExport() override;
    virtual QVariantMap constantsToExport() override;
    virtual void setBridge(Bridge* bridge) override;

private:
    QScopedPointer<RNSecureRandomPrivate> d_ptr;
};

#endif // RNSECURERANDOM_H
