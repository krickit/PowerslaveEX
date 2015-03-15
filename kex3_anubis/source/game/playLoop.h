//
// Copyright(C) 2014-2015 Samuel Villarreal
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#ifndef __PLAYLOOP_H__
#define __PLAYLOOP_H__

#include "renderView.h"
#include "renderScene.h"
#include "hud.h"

class kexPlayLoop : public kexGameLoop
{
public:
    kexPlayLoop(void);
    ~kexPlayLoop(void);

    void                        Init(void);
    void                        Start(void);
    void                        Stop(void);
    void                        Draw(void);
    void                        Tick(void);
    void                        Print(const char *string);
    bool                        ProcessInput(inputEvent_t *ev);
    const int                   GetWaterVelocityPoint(const float x, const float y);
    
    kexRenderView               &View(void) { return renderView; }
    const int                   Ticks(void) const { return ticks; }
    const int                   MaxWaterMagnitude(void) { return waterMaxMagnitude; }
    void                        PickupFlash(void) { hud.SetPickupFlash(); }
    void                        DamageFlash(void) { hud.SetDamageFlash(); }
    void                        ElectrocuteFlash(void) { hud.SetElectrocuteFlash(); }
    const bool                  AutomapEnabled(void) { return bShowAutomap; }
    void                        ToggleAutomap(const bool bToggle) { bShowAutomap = bToggle; }
    void                        ToggleMapAll(const bool bToggle) { bMapAll = bToggle; }
    const bool                  IsPaused(void) const { return bPaused; }
    void                        TogglePause(const bool bToggle) { bPaused = bToggle; }
    void                        ToggleInventoryMenu(void);
    
private:
    void                        InitWater(void);
    void                        UpdateWater(void);
    void                        DrawInventoryMenu(void);
    void                        DrawAutomap(void);
    void                        DrawAutomapArrow(kexRenderView &view, const float angle, const kexVec3 &pos,
                                                 const float size, const byte r, const byte g, const byte b);
    void                        DrawAutomapActors(kexRenderView &view);
    void                        DrawAutomapWalls(kexRenderView &view);

    int                         ticks;
    kexHud                      hud;
    kexRenderView               renderView;
    kexRenderScene              renderScene;
    kexTexture                  *menuBackTexture;
    int                         waterAccelPoints[16][16];
    int                         waterVelocityPoints[16][16];
    int                         waterMaxMagnitude;
    bool                        bShowAutomap;
    bool                        bMapAll;
    bool                        bPaused;
    bool                        bInventoryActive;
};

#endif
