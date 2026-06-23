#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include <QList>
#include "proc_interface.h"

class plugin_manager
{
private:
    plugin_manager() = default;
    ~plugin_manager() = default;

    plugin_manager(const plugin_manager&) = delete;
    plugin_manager& operator=(const plugin_manager&) = delete;

    QList<proc_interface*> m_processors;

public:

    static plugin_manager& instance() {
        static plugin_manager singleInstance;
        return singleInstance;
    }

    void loadPlugins();

    QList<proc_interface*> getProcessors() const { return m_processors; }
};

#endif // PLUGIN_MANAGER_H
