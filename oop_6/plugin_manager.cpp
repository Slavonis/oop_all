#include "plugin_manager.h"
#include <QDir>
#include <QPluginLoader>
#include <QCoreApplication>
#include <QDebug>

void plugin_manager::loadPlugins() {
    QDir pluginsDir(QCoreApplication::applicationDirPath() + "/processors");
    m_processors.clear();

    for (const QString &fileName : pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();

        if (plugin) {
            auto *processor = qobject_cast<proc_interface*>(plugin);
            if (processor) {
                m_processors.append(processor);
                qDebug() << "Successfully attached plugin:" << processor->getPluginName();
            }
        } else {
            qDebug() << "Failed to mount target library:" << loader.errorString();
        }
    }
}
