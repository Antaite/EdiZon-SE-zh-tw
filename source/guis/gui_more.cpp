#include "guis/gui_more.hpp"
#include "helpers/config.hpp"
GuiMore::GuiMore() : Gui() {
  Config::getConfig()->option_once = false;
  // m_edizon_dir = Config::getConfig()->edizon_dir;
}
GuiMore::~GuiMore() {
}
void GuiMore::update() {
  Gui::update();
}
static const char *const optionNames[] = {"不自動連接 \uE0A2", "中斷連接後不自動離開 \uE0A3", "不再顯示這個畫面 \uE0B4"};
bool screen2 = false;
void draw2() {

}
void GuiMore::draw() {
  if (screen2)
  {
    draw2();
    return;
  }
  std::stringstream extra_seg_str, two_value_range_str, bit_mask_str;
  extra_seg_str << "\uE0B2 +  \uE0B1 -  額外 MB " << Config::getConfig()->extraMB;
  two_value_range_str << "\uE0A5 +  \uE0A4 - 雙數值搜尋範圍 " << Config::getConfig()->two_value_range;
  bit_mask_str << "\uE0A6 BM=" << std::uppercase << std::hex << std::setfill('0') << std::setw(16) << Config::getConfig()->bitmask;
  Gui::beginDraw();
  Gui::drawRectangle(0, 0, Gui::g_framebuffer_width, Gui::g_framebuffer_height, Gui::makeColor(0x30, 0x39, 0x29, 0xFF));
  Gui::drawTextAligned(fontHuge, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2 - 100, COLOR_WHITE, "更多選項", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2, COLOR_BLACK, "", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2+60, COLOR_BLACK, "用 X、Y、- 切換選項；停用這個畫面後，用 R+B 離開，下次啟動會再顯示", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 5, Gui::g_framebuffer_height / 2 + 200, Config::getConfig()->enabletargetedscan ? COLOR_WHITE : COLOR_BLACK, "\uE0AF 啟用目標掃描", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2 + 200, Config::getConfig()->enabletargetedscan ? COLOR_WHITE : COLOR_BLACK, extra_seg_str.str().c_str(), ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width *4 / 5, Gui::g_framebuffer_height / 2 + 200, Config::getConfig()->use_absolute_address ? COLOR_WHITE : COLOR_BLACK, "\uE0B0 使用絕對位址", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 5, Gui::g_framebuffer_height / 2 + 250, Config::getConfig()->easymode ? COLOR_WHITE : COLOR_BLACK, "\uE0C4 簡易模式", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width * 4 / 5, Gui::g_framebuffer_height / 2+250, Config::getConfig()->freeze ? COLOR_WHITE : COLOR_BLACK, "\uE0C5 加入凍結遊戲代碼", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2 + 250, COLOR_WHITE, two_value_range_str.str().c_str() , ALIGNED_CENTER);//"\uE070  不再顯示這個警告"
  // for (u8 i = 0; i < 3; i++)
  // {
  //   // Gui::drawRectangled((Gui::g_framebuffer_width / 4) * (i + 1), Gui::g_framebuffer_height / 2 + 270, 300, 60, currTheme.separatorColor);
  //   Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 4) * (i + 1), Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->options[i] ? COLOR_WHITE : COLOR_BLACK, optionNames[i], ALIGNED_CENTER);
  // }
  // Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 5), Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->extra_value ? COLOR_WHITE : COLOR_BLACK, "\uE0A2 使用額外搜尋數值", ALIGNED_CENTER);
  // Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 2), Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->show_previous_values ? COLOR_WHITE : COLOR_BLACK, "\uE0A3 show previous values", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 5), Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->options[0] ? COLOR_WHITE : COLOR_BLACK, optionNames[0], ALIGNED_CENTER);
  Gui::drawTextAligned(font20, (Gui::g_framebuffer_width / 2), Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->options[1] ? COLOR_WHITE : COLOR_BLACK, optionNames[1], ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width * 4 / 5, Gui::g_framebuffer_height / 2 + 300, Config::getConfig()->exclude_ptr_candidates ? COLOR_WHITE : COLOR_BLACK, "\uE0B4 排除指標候選", ALIGNED_CENTER);

  Gui::drawTextAligned(font20, Gui::g_framebuffer_width * 4 / 5, Gui::g_framebuffer_height / 2 + 150, COLOR_WHITE, "關於 \uE0B3", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 5, Gui::g_framebuffer_height / 2 + 150, Config::getConfig()->use_bitmask ? COLOR_WHITE : COLOR_BLACK, Config::getConfig()->use_bitmask ? bit_mask_str.str().c_str() : "\uE0A6 使用位元遮罩", ALIGNED_CENTER);
  Gui::drawTextAligned(font20, Gui::g_framebuffer_width / 2, Gui::g_framebuffer_height / 2 + 150, Config::getConfig()->swap_jumpback_button ? COLOR_WHITE : COLOR_BLACK, "\uE0A7 交換回跳按鍵", ALIGNED_CENTER);
  Gui::endDraw();
}
// u32 kheld = hidKeysHeld(CONTROLLER_PLAYER_1) | hidKeysHeld(CONTROLLER_HANDHELD);
void onInput2(u32 kdown)
{

}
void GuiMore::onInput(u32 kdown)
{
  if (screen2)
  {
    onInput2(kdown);
    return;
  }
  if (kdown & KEY_L)
  {
    // m_edizon_dir = "/switch/EdiZon/1";
    if (Config::getConfig()->two_value_range > 0)
        Config::getConfig()->two_value_range = Config::getConfig()->two_value_range - 1;
  }
  else if (kdown & KEY_R)
  {
    // m_edizon_dir = "/switch/EdiZon/2";
    Config::getConfig()->two_value_range = Config::getConfig()->two_value_range + 1;
  }
  if (kdown & KEY_ZL)
  {
    // m_edizon_dir = "/switch/EdiZon/3";
    Config::getConfig()->use_bitmask = !Config::getConfig()->use_bitmask;
    if (Config::getConfig()->use_bitmask) {
        if (Config::getConfig()->bitmask == 0) {
            Config::getConfig()->bitmask = 0xFFFFFFFFFFFFFFFF;
        };
        char input[19];
        char initialString[21];
        snprintf(initialString, sizeof(initialString), "0x%016lX", Config::getConfig()->bitmask);
        if (Gui::requestKeyboardInput("輸入數值", "輸入要套用在搜尋數值上的位元遮罩。", initialString, SwkbdType_QWERTY, input, 18)) {
            Config::getConfig()->bitmask = static_cast<u64>(std::stoul(input, nullptr, 16));
        }
    }
  }
  else if (kdown & KEY_ZR)
  {
    Config::getConfig()->swap_jumpback_button = !Config::getConfig()->swap_jumpback_button;
    // m_edizon_dir = "/switch/EdiZon/4";
  }
  else if (kdown & KEY_B)
  {
    // m_edizon_dir = "/switch/EdiZon";
  }
  else if (kdown & KEY_X)
  {
    Config::getConfig()->options[0] = !Config::getConfig()->options[0];
    // Config::getConfig()->extra_value = !Config::getConfig()->extra_value;
  }
  else if (kdown & KEY_Y)
  {
    Config::getConfig()->options[1] = !Config::getConfig()->options[1];
    // Config::getConfig()->show_previous_values = !Config::getConfig()->show_previous_values;
  }
  else if (kdown & KEY_MINUS)
  {
    Config::getConfig()->exclude_ptr_candidates = !Config::getConfig()->exclude_ptr_candidates;
  }
  else if (kdown & KEY_DUP)
  {
    Config::getConfig()->enabletargetedscan = !Config::getConfig()->enabletargetedscan;
  }
  else if (kdown & KEY_DRIGHT)
  {
    Config::getConfig()->extraMB = Config::getConfig()->extraMB + 1;
  }
  else if (kdown & KEY_DLEFT)
  {
    if (Config::getConfig()->extraMB > 0)
      Config::getConfig()->extraMB = Config::getConfig()->extraMB - 1;
  }
  else if (kdown & KEY_DDOWN)
  {
    Config::getConfig()->use_absolute_address = !Config::getConfig()->use_absolute_address;
  }
  else if (kdown & KEY_PLUS)
  {
    Gui::g_nextGui = GUI_ABOUT;
  }
  else if (kdown & KEY_LSTICK) 
  {
    Config::getConfig()->easymode = !Config::getConfig()->easymode;
    Config::getConfig()->options[0] = true;
  }
  else if (kdown & KEY_RSTICK) 
  {
    Config::getConfig()->freeze = !Config::getConfig()->freeze;
  }
  else if (kdown & KEY_A)
  {
    Gui::g_nextGui = GUI_CHEATS;
    memcpy(Config::getConfig()->edizon_dir, m_edizon_dir.c_str(), m_edizon_dir.size());
    Config::getConfig()->edizon_dir[m_edizon_dir.size()] = 0;
    Config::writeConfig();
  }
}

void GuiMore::onTouch(touchPosition &touch) {
  if (touch.px > 400 && touch.px < 900 && touch.py > 600 && touch.py < 660) {
    Config::getConfig()->hideSX = !Config::getConfig()->hideSX;
    Config::writeConfig();
  }
}

void GuiMore::onGesture(touchPosition startPosition, touchPosition endPosition, bool finish) {

}
