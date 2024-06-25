#if HAS_TFT // VIEW_128x64

#include "OLEDView_128x64.h"
#include "DisplayDriverFactory.h"
#include "ILog.h"
#include "OLEDViewController.h"
#include "ui.h" // this is the ui generated by eez-studio
#include <cstdio>
#include <ctime>
#include <functional>

OLEDView_128x64 *OLEDView_128x64::gui = nullptr;

OLEDView_128x64 *OLEDView_128x64::instance(void)
{
    if (!gui)
        gui = new OLEDView_128x64(nullptr, DisplayDriverFactory::create(128, 64));
    return gui;
}

OLEDView_128x64 *OLEDView_128x64::instance(const DisplayDriverConfig &cfg)
{
    if (!gui)
        gui = new OLEDView_128x64(&cfg, DisplayDriverFactory::create(cfg));
    return gui;
}

OLEDView_128x64::OLEDView_128x64(const DisplayDriverConfig *cfg, DisplayDriver *driver)
    : MeshtasticView(cfg, driver, new OLEDViewController)
{
}

void OLEDView_128x64::init(IClientBase *client)
{
    ILOG_DEBUG("OLEDView_128x64 init...\n");
    MeshtasticView::init(client);
    // ui_events_init();
}

void OLEDView_128x64::task_handler(void)
{
    MeshtasticView::task_handler();
}
#endif