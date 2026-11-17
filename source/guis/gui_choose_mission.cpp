#include "guis/gui_choose_mission.hpp"
#include "helpers/config.hpp"

GuiChooseMission::GuiChooseMission() : Gui() {
  Config::getConfig()->option_once = false;
  // m_edizon_dir = Config::getConfig()->edizon_dir;
}
GuiChooseMission::~GuiChooseMission() {
}
void GuiChooseMission::update() {
  Gui::update();
}
static const char *const optionNames[] = {"\uE0A2 不自動連接", "\uE0A3 中斷連接後不自動離開", "\uE0B4 不再顯示這個畫面"};
void GuiChooseMission::draw() {
  Gui::beginDraw();
  Gui::drawRectangle(0, 0, Gui::g_framebuffer_width, Gui::g_framebuffer_height, Gui::makeColor(0x00, 0x39, 0x29, 0xFF));
  Gui::drawTextAligned(fontHuge, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2 - 100, COLOR_WHITE, "歡迎", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2, COLOR_WHITE, "用 L、R、ZL、ZR 和 B 選擇搜尋資料的儲存位置，按 A 繼續", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2+60, COLOR_WHITE, "用 X、Y、- 切換選項；停用這個畫面後，用 R+B 離開，下次啟動會再顯示", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 5, Gui::g_framebuffer_height / 2+200, Config::getConfig()->disablerangeonunknown ? COLOR_WHITE : COLOR_BLACK, "\uE0AF 未知數值搜尋不使用範圍", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 5, Gui::g_framebuffer_height / 2 + 150, Config::getConfig()->separatebookmark ? COLOR_WHITE : COLOR_BLACK, "\uE0B1 書籤分開存放", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2+200, Config::getConfig()->enablecheats ? COLOR_WHITE : COLOR_BLACK, "\uE0B2 允許覆蓋金手指", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width *4 / 5, Gui::g_framebuffer_height / 2+200, COLOR_BLACK, "\uE0B0 更新金手指資料庫", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 5, Gui::g_framebuffer_height / 2+250, Config::getConfig()->deletebookmark ? COLOR_WHITE : COLOR_BLACK, "\uE0C4 清除所有書籤", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width * 4 / 5, Gui::g_framebuffer_height / 2 + 250, (Config::getConfig()->freeze || Config::getConfig()->enabletargetedscan || Config::getConfig()->easymode) ? COLOR_WHITE : COLOR_BLACK, "\uE0C5 更多選項", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2 + 250, COLOR_WHITE, m_edizon_dir.c_str() , ALIGNED_CENTER);//"\uE070  不再顯示這個警告"
  // for (u8 i = 0; i < 3; i++)
  // {
    // Gui::drawRectangled((Gui::g_framebuffer_width / 4) * (i + 1), Gui::g_framebuffer_height / 2 + 270, 300, 60, currTheme.separatorColor);
    // Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 5) , Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->options[0] ? COLOR_WHITE : COLOR_BLACK, optionNames[0], ALIGNED_CENTER);
    // Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 2) , Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->options[1] ? COLOR_WHITE : COLOR_BLACK, optionNames[1], ALIGNED_CENTER);
  Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 5), Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->extra_value ? COLOR_WHITE : COLOR_BLACK, "\uE0A2 使用額外搜尋數值", ALIGNED_CENTER);
  // Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 2), Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->show_previous_values ? COLOR_WHITE : COLOR_BLACK, "\uE0A3 show previous values", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 2), Gui::g_framebuffer_height / 2 + 300, COLOR_WHITE, "\uE0A3 管理系統模組", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 5) * 4, Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->options[2] ? COLOR_WHITE : COLOR_BLACK, optionNames[2], ALIGNED_CENTER);
  // }
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width * 4 / 5, Gui::g_framebuffer_height / 2 + 150, COLOR_WHITE, "關於 \uE0B3", ALIGNED_CENTER);
  Gui::endDraw();
}
// u32 kheld = hidKeysHeld(CONTROLLER_PLAYER_1) | hidKeysHeld(CONTROLLER_HANDHELD);
void GuiChooseMission::onInput(u32 kdown)
{
  if (kdown & KEY_L)
  {
    m_edizon_dir = "/switch/EdiZon/1";
  }
  else if (kdown & KEY_R)
  {
    m_edizon_dir = "/switch/EdiZon/2";
  }
    if (kdown & KEY_ZL)
  {
    m_edizon_dir = "/switch/EdiZon/3";
  }
  else if (kdown & KEY_ZR)
  {
    m_edizon_dir = "/switch/EdiZon/4";
  }
  else if (kdown & KEY_B)
  {
    m_edizon_dir = "/switch/EdiZon";
  }
  else if (kdown & KEY_X)
  {
    // Config::getConfig()->options[0] = !Config::getConfig()->options[0];
    Config::getConfig()->extra_value = !Config::getConfig()->extra_value;
  }
  else if (kdown & KEY_Y)
  {
    // Config::getConfig()->options[1] = !Config::getConfig()->options[1];
    Gui::g_nextGui = GUI_Sysmodule;
    // Config::getConfig()->show_previous_values = !Config::getConfig()->show_previous_values;
  }
  else if (kdown & KEY_MINUS)
  {
    Config::getConfig()->options[2] = !Config::getConfig()->options[2];
  }
  else if (kdown & KEY_DUP)
  {
    Config::getConfig()->disablerangeonunknown = !Config::getConfig()->disablerangeonunknown;
  }
  else if (kdown & KEY_DRIGHT)
  {
    Config::getConfig()->enablecheats = !Config::getConfig()->enablecheats;
  }
  else if (kdown & KEY_DLEFT)
  {
    Config::getConfig()->separatebookmark = !Config::getConfig()->separatebookmark;
  }
    else if (kdown & KEY_DDOWN)
  {
    Gui::g_nextGui = GUI_CHEATDB;
  }
  else if (kdown & KEY_PLUS)
  {
    Gui::g_nextGui = GUI_ABOUT;
  }
  else if (kdown & KEY_LSTICK) 
  {
    Config::getConfig()->deletebookmark = !Config::getConfig()->deletebookmark;
  }
  else if (kdown & KEY_RSTICK) 
  {
    Gui::g_nextGui = GUI_MORE;
    // Config::getConfig()->freeze = !Config::getConfig()->freeze;
  }
  else if (kdown & KEY_A)
  {
    Gui::g_nextGui = GUI_CHEATS;
    memcpy(Config::getConfig()->edizon_dir, m_edizon_dir.c_str(), m_edizon_dir.size());
    Config::getConfig()->edizon_dir[m_edizon_dir.size()] = 0;
    Config::writeConfig();
  }
}

void GuiChooseMission::onTouch(touchPosition &touch) {
  if (touch.px > 400 && touch.px < 900 && touch.py > 600 && touch.py < 660) {
    Config::getConfig()->hideSX = !Config::getConfig()->hideSX;
    Config::writeConfig();
  }
}

void GuiChooseMission::onGesture(touchPosition startPosition, touchPosition endPosition, bool finish) {

}
