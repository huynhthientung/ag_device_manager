#ifndef DEBUG_H
#define DEBUG_H

#include <QDebug>

#define DEBUG(message) \
( \
    (qDebug() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()), \
    (void)0 \
)

#define WARN(message) \
( \
    (qWarning() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()), \
    (void)0 \
)

#define CRITICAL(message) \
( \
    (qCritical() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()), \
    (void)0 \
)

#define FATAL(message) \
( \
    (qFatal("%s : %s", Q_FUNC_INFO, QString(message).toStdString().c_str())), \
    (void)0 \
)
#endif // DEBUG_H
