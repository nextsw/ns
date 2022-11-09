#ifndef PACKAGES_FLUTTER_SRC_SERVICES_KEYBOARD_KEY.G
#define PACKAGES_FLUTTER_SRC_SERVICES_KEYBOARD_KEY.G
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>


class KeyboardKeyCls : public ObjectCls {
public:

     KeyboardKeyCls();
private:

};
using KeyboardKey = std::shared_ptr<KeyboardKeyCls>;

class LogicalKeyboardKeyCls : public KeyboardKeyCls {
public:
    int keyId;

    static int valueMask;

    static int planeMask;

    static int unicodePlane;

    static int unprintablePlane;

    static int flutterPlane;

    static int startOfPlatformPlanes;

    static int androidPlane;

    static int fuchsiaPlane;

    static int iosPlane;

    static int macosPlane;

    static int gtkPlane;

    static int windowsPlane;

    static int webPlane;

    static int glfwPlane;

    static LogicalKeyboardKey space;

    static LogicalKeyboardKey exclamation;

    static LogicalKeyboardKey quote;

    static LogicalKeyboardKey numberSign;

    static LogicalKeyboardKey dollar;

    static LogicalKeyboardKey percent;

    static LogicalKeyboardKey ampersand;

    static LogicalKeyboardKey quoteSingle;

    static LogicalKeyboardKey parenthesisLeft;

    static LogicalKeyboardKey parenthesisRight;

    static LogicalKeyboardKey asterisk;

    static LogicalKeyboardKey add;

    static LogicalKeyboardKey comma;

    static LogicalKeyboardKey minus;

    static LogicalKeyboardKey period;

    static LogicalKeyboardKey slash;

    static LogicalKeyboardKey digit0;

    static LogicalKeyboardKey digit1;

    static LogicalKeyboardKey digit2;

    static LogicalKeyboardKey digit3;

    static LogicalKeyboardKey digit4;

    static LogicalKeyboardKey digit5;

    static LogicalKeyboardKey digit6;

    static LogicalKeyboardKey digit7;

    static LogicalKeyboardKey digit8;

    static LogicalKeyboardKey digit9;

    static LogicalKeyboardKey colon;

    static LogicalKeyboardKey semicolon;

    static LogicalKeyboardKey less;

    static LogicalKeyboardKey equal;

    static LogicalKeyboardKey greater;

    static LogicalKeyboardKey question;

    static LogicalKeyboardKey at;

    static LogicalKeyboardKey bracketLeft;

    static LogicalKeyboardKey backslash;

    static LogicalKeyboardKey bracketRight;

    static LogicalKeyboardKey caret;

    static LogicalKeyboardKey underscore;

    static LogicalKeyboardKey backquote;

    static LogicalKeyboardKey keyA;

    static LogicalKeyboardKey keyB;

    static LogicalKeyboardKey keyC;

    static LogicalKeyboardKey keyD;

    static LogicalKeyboardKey keyE;

    static LogicalKeyboardKey keyF;

    static LogicalKeyboardKey keyG;

    static LogicalKeyboardKey keyH;

    static LogicalKeyboardKey keyI;

    static LogicalKeyboardKey keyJ;

    static LogicalKeyboardKey keyK;

    static LogicalKeyboardKey keyL;

    static LogicalKeyboardKey keyM;

    static LogicalKeyboardKey keyN;

    static LogicalKeyboardKey keyO;

    static LogicalKeyboardKey keyP;

    static LogicalKeyboardKey keyQ;

    static LogicalKeyboardKey keyR;

    static LogicalKeyboardKey keyS;

    static LogicalKeyboardKey keyT;

    static LogicalKeyboardKey keyU;

    static LogicalKeyboardKey keyV;

    static LogicalKeyboardKey keyW;

    static LogicalKeyboardKey keyX;

    static LogicalKeyboardKey keyY;

    static LogicalKeyboardKey keyZ;

    static LogicalKeyboardKey braceLeft;

    static LogicalKeyboardKey bar;

    static LogicalKeyboardKey braceRight;

    static LogicalKeyboardKey tilde;

    static LogicalKeyboardKey unidentified;

    static LogicalKeyboardKey backspace;

    static LogicalKeyboardKey tab;

    static LogicalKeyboardKey enter;

    static LogicalKeyboardKey escape;

    static LogicalKeyboardKey delete;

    static LogicalKeyboardKey accel;

    static LogicalKeyboardKey altGraph;

    static LogicalKeyboardKey capsLock;

    static LogicalKeyboardKey fn;

    static LogicalKeyboardKey fnLock;

    static LogicalKeyboardKey hyper;

    static LogicalKeyboardKey numLock;

    static LogicalKeyboardKey scrollLock;

    static LogicalKeyboardKey superKey;

    static LogicalKeyboardKey symbol;

    static LogicalKeyboardKey symbolLock;

    static LogicalKeyboardKey shiftLevel5;

    static LogicalKeyboardKey arrowDown;

    static LogicalKeyboardKey arrowLeft;

    static LogicalKeyboardKey arrowRight;

    static LogicalKeyboardKey arrowUp;

    static LogicalKeyboardKey end;

    static LogicalKeyboardKey home;

    static LogicalKeyboardKey pageDown;

    static LogicalKeyboardKey pageUp;

    static LogicalKeyboardKey clear;

    static LogicalKeyboardKey copy;

    static LogicalKeyboardKey crSel;

    static LogicalKeyboardKey cut;

    static LogicalKeyboardKey eraseEof;

    static LogicalKeyboardKey exSel;

    static LogicalKeyboardKey insert;

    static LogicalKeyboardKey paste;

    static LogicalKeyboardKey redo;

    static LogicalKeyboardKey undo;

    static LogicalKeyboardKey accept;

    static LogicalKeyboardKey again;

    static LogicalKeyboardKey attn;

    static LogicalKeyboardKey cancel;

    static LogicalKeyboardKey contextMenu;

    static LogicalKeyboardKey execute;

    static LogicalKeyboardKey find;

    static LogicalKeyboardKey help;

    static LogicalKeyboardKey pause;

    static LogicalKeyboardKey play;

    static LogicalKeyboardKey props;

    static LogicalKeyboardKey select;

    static LogicalKeyboardKey zoomIn;

    static LogicalKeyboardKey zoomOut;

    static LogicalKeyboardKey brightnessDown;

    static LogicalKeyboardKey brightnessUp;

    static LogicalKeyboardKey camera;

    static LogicalKeyboardKey eject;

    static LogicalKeyboardKey logOff;

    static LogicalKeyboardKey power;

    static LogicalKeyboardKey powerOff;

    static LogicalKeyboardKey printScreen;

    static LogicalKeyboardKey hibernate;

    static LogicalKeyboardKey standby;

    static LogicalKeyboardKey wakeUp;

    static LogicalKeyboardKey allCandidates;

    static LogicalKeyboardKey alphanumeric;

    static LogicalKeyboardKey codeInput;

    static LogicalKeyboardKey compose;

    static LogicalKeyboardKey convert;

    static LogicalKeyboardKey finalMode;

    static LogicalKeyboardKey groupFirst;

    static LogicalKeyboardKey groupLast;

    static LogicalKeyboardKey groupNext;

    static LogicalKeyboardKey groupPrevious;

    static LogicalKeyboardKey modeChange;

    static LogicalKeyboardKey nextCandidate;

    static LogicalKeyboardKey nonConvert;

    static LogicalKeyboardKey previousCandidate;

    static LogicalKeyboardKey process;

    static LogicalKeyboardKey singleCandidate;

    static LogicalKeyboardKey hangulMode;

    static LogicalKeyboardKey hanjaMode;

    static LogicalKeyboardKey junjaMode;

    static LogicalKeyboardKey eisu;

    static LogicalKeyboardKey hankaku;

    static LogicalKeyboardKey hiragana;

    static LogicalKeyboardKey hiraganaKatakana;

    static LogicalKeyboardKey kanaMode;

    static LogicalKeyboardKey kanjiMode;

    static LogicalKeyboardKey katakana;

    static LogicalKeyboardKey romaji;

    static LogicalKeyboardKey zenkaku;

    static LogicalKeyboardKey zenkakuHankaku;

    static LogicalKeyboardKey f1;

    static LogicalKeyboardKey f2;

    static LogicalKeyboardKey f3;

    static LogicalKeyboardKey f4;

    static LogicalKeyboardKey f5;

    static LogicalKeyboardKey f6;

    static LogicalKeyboardKey f7;

    static LogicalKeyboardKey f8;

    static LogicalKeyboardKey f9;

    static LogicalKeyboardKey f10;

    static LogicalKeyboardKey f11;

    static LogicalKeyboardKey f12;

    static LogicalKeyboardKey f13;

    static LogicalKeyboardKey f14;

    static LogicalKeyboardKey f15;

    static LogicalKeyboardKey f16;

    static LogicalKeyboardKey f17;

    static LogicalKeyboardKey f18;

    static LogicalKeyboardKey f19;

    static LogicalKeyboardKey f20;

    static LogicalKeyboardKey f21;

    static LogicalKeyboardKey f22;

    static LogicalKeyboardKey f23;

    static LogicalKeyboardKey f24;

    static LogicalKeyboardKey soft1;

    static LogicalKeyboardKey soft2;

    static LogicalKeyboardKey soft3;

    static LogicalKeyboardKey soft4;

    static LogicalKeyboardKey soft5;

    static LogicalKeyboardKey soft6;

    static LogicalKeyboardKey soft7;

    static LogicalKeyboardKey soft8;

    static LogicalKeyboardKey close;

    static LogicalKeyboardKey mailForward;

    static LogicalKeyboardKey mailReply;

    static LogicalKeyboardKey mailSend;

    static LogicalKeyboardKey mediaPlayPause;

    static LogicalKeyboardKey mediaStop;

    static LogicalKeyboardKey mediaTrackNext;

    static LogicalKeyboardKey mediaTrackPrevious;

    static LogicalKeyboardKey newKey;

    static LogicalKeyboardKey open;

    static LogicalKeyboardKey print;

    static LogicalKeyboardKey save;

    static LogicalKeyboardKey spellCheck;

    static LogicalKeyboardKey audioVolumeDown;

    static LogicalKeyboardKey audioVolumeUp;

    static LogicalKeyboardKey audioVolumeMute;

    static LogicalKeyboardKey launchApplication2;

    static LogicalKeyboardKey launchCalendar;

    static LogicalKeyboardKey launchMail;

    static LogicalKeyboardKey launchMediaPlayer;

    static LogicalKeyboardKey launchMusicPlayer;

    static LogicalKeyboardKey launchApplication1;

    static LogicalKeyboardKey launchScreenSaver;

    static LogicalKeyboardKey launchSpreadsheet;

    static LogicalKeyboardKey launchWebBrowser;

    static LogicalKeyboardKey launchWebCam;

    static LogicalKeyboardKey launchWordProcessor;

    static LogicalKeyboardKey launchContacts;

    static LogicalKeyboardKey launchPhone;

    static LogicalKeyboardKey launchAssistant;

    static LogicalKeyboardKey launchControlPanel;

    static LogicalKeyboardKey browserBack;

    static LogicalKeyboardKey browserFavorites;

    static LogicalKeyboardKey browserForward;

    static LogicalKeyboardKey browserHome;

    static LogicalKeyboardKey browserRefresh;

    static LogicalKeyboardKey browserSearch;

    static LogicalKeyboardKey browserStop;

    static LogicalKeyboardKey audioBalanceLeft;

    static LogicalKeyboardKey audioBalanceRight;

    static LogicalKeyboardKey audioBassBoostDown;

    static LogicalKeyboardKey audioBassBoostUp;

    static LogicalKeyboardKey audioFaderFront;

    static LogicalKeyboardKey audioFaderRear;

    static LogicalKeyboardKey audioSurroundModeNext;

    static LogicalKeyboardKey avrInput;

    static LogicalKeyboardKey avrPower;

    static LogicalKeyboardKey channelDown;

    static LogicalKeyboardKey channelUp;

    static LogicalKeyboardKey colorF0Red;

    static LogicalKeyboardKey colorF1Green;

    static LogicalKeyboardKey colorF2Yellow;

    static LogicalKeyboardKey colorF3Blue;

    static LogicalKeyboardKey colorF4Grey;

    static LogicalKeyboardKey colorF5Brown;

    static LogicalKeyboardKey closedCaptionToggle;

    static LogicalKeyboardKey dimmer;

    static LogicalKeyboardKey displaySwap;

    static LogicalKeyboardKey exit;

    static LogicalKeyboardKey favoriteClear0;

    static LogicalKeyboardKey favoriteClear1;

    static LogicalKeyboardKey favoriteClear2;

    static LogicalKeyboardKey favoriteClear3;

    static LogicalKeyboardKey favoriteRecall0;

    static LogicalKeyboardKey favoriteRecall1;

    static LogicalKeyboardKey favoriteRecall2;

    static LogicalKeyboardKey favoriteRecall3;

    static LogicalKeyboardKey favoriteStore0;

    static LogicalKeyboardKey favoriteStore1;

    static LogicalKeyboardKey favoriteStore2;

    static LogicalKeyboardKey favoriteStore3;

    static LogicalKeyboardKey guide;

    static LogicalKeyboardKey guideNextDay;

    static LogicalKeyboardKey guidePreviousDay;

    static LogicalKeyboardKey info;

    static LogicalKeyboardKey instantReplay;

    static LogicalKeyboardKey link;

    static LogicalKeyboardKey listProgram;

    static LogicalKeyboardKey liveContent;

    static LogicalKeyboardKey lock;

    static LogicalKeyboardKey mediaApps;

    static LogicalKeyboardKey mediaFastForward;

    static LogicalKeyboardKey mediaLast;

    static LogicalKeyboardKey mediaPause;

    static LogicalKeyboardKey mediaPlay;

    static LogicalKeyboardKey mediaRecord;

    static LogicalKeyboardKey mediaRewind;

    static LogicalKeyboardKey mediaSkip;

    static LogicalKeyboardKey nextFavoriteChannel;

    static LogicalKeyboardKey nextUserProfile;

    static LogicalKeyboardKey onDemand;

    static LogicalKeyboardKey pInPDown;

    static LogicalKeyboardKey pInPMove;

    static LogicalKeyboardKey pInPToggle;

    static LogicalKeyboardKey pInPUp;

    static LogicalKeyboardKey playSpeedDown;

    static LogicalKeyboardKey playSpeedReset;

    static LogicalKeyboardKey playSpeedUp;

    static LogicalKeyboardKey randomToggle;

    static LogicalKeyboardKey rcLowBattery;

    static LogicalKeyboardKey recordSpeedNext;

    static LogicalKeyboardKey rfBypass;

    static LogicalKeyboardKey scanChannelsToggle;

    static LogicalKeyboardKey screenModeNext;

    static LogicalKeyboardKey settings;

    static LogicalKeyboardKey splitScreenToggle;

    static LogicalKeyboardKey stbInput;

    static LogicalKeyboardKey stbPower;

    static LogicalKeyboardKey subtitle;

    static LogicalKeyboardKey teletext;

    static LogicalKeyboardKey tv;

    static LogicalKeyboardKey tvInput;

    static LogicalKeyboardKey tvPower;

    static LogicalKeyboardKey videoModeNext;

    static LogicalKeyboardKey wink;

    static LogicalKeyboardKey zoomToggle;

    static LogicalKeyboardKey dvr;

    static LogicalKeyboardKey mediaAudioTrack;

    static LogicalKeyboardKey mediaSkipBackward;

    static LogicalKeyboardKey mediaSkipForward;

    static LogicalKeyboardKey mediaStepBackward;

    static LogicalKeyboardKey mediaStepForward;

    static LogicalKeyboardKey mediaTopMenu;

    static LogicalKeyboardKey navigateIn;

    static LogicalKeyboardKey navigateNext;

    static LogicalKeyboardKey navigateOut;

    static LogicalKeyboardKey navigatePrevious;

    static LogicalKeyboardKey pairing;

    static LogicalKeyboardKey mediaClose;

    static LogicalKeyboardKey audioBassBoostToggle;

    static LogicalKeyboardKey audioTrebleDown;

    static LogicalKeyboardKey audioTrebleUp;

    static LogicalKeyboardKey microphoneToggle;

    static LogicalKeyboardKey microphoneVolumeDown;

    static LogicalKeyboardKey microphoneVolumeUp;

    static LogicalKeyboardKey microphoneVolumeMute;

    static LogicalKeyboardKey speechCorrectionList;

    static LogicalKeyboardKey speechInputToggle;

    static LogicalKeyboardKey appSwitch;

    static LogicalKeyboardKey call;

    static LogicalKeyboardKey cameraFocus;

    static LogicalKeyboardKey endCall;

    static LogicalKeyboardKey goBack;

    static LogicalKeyboardKey goHome;

    static LogicalKeyboardKey headsetHook;

    static LogicalKeyboardKey lastNumberRedial;

    static LogicalKeyboardKey notification;

    static LogicalKeyboardKey mannerMode;

    static LogicalKeyboardKey voiceDial;

    static LogicalKeyboardKey tv3DMode;

    static LogicalKeyboardKey tvAntennaCable;

    static LogicalKeyboardKey tvAudioDescription;

    static LogicalKeyboardKey tvAudioDescriptionMixDown;

    static LogicalKeyboardKey tvAudioDescriptionMixUp;

    static LogicalKeyboardKey tvContentsMenu;

    static LogicalKeyboardKey tvDataService;

    static LogicalKeyboardKey tvInputComponent1;

    static LogicalKeyboardKey tvInputComponent2;

    static LogicalKeyboardKey tvInputComposite1;

    static LogicalKeyboardKey tvInputComposite2;

    static LogicalKeyboardKey tvInputHDMI1;

    static LogicalKeyboardKey tvInputHDMI2;

    static LogicalKeyboardKey tvInputHDMI3;

    static LogicalKeyboardKey tvInputHDMI4;

    static LogicalKeyboardKey tvInputVGA1;

    static LogicalKeyboardKey tvMediaContext;

    static LogicalKeyboardKey tvNetwork;

    static LogicalKeyboardKey tvNumberEntry;

    static LogicalKeyboardKey tvRadioService;

    static LogicalKeyboardKey tvSatellite;

    static LogicalKeyboardKey tvSatelliteBS;

    static LogicalKeyboardKey tvSatelliteCS;

    static LogicalKeyboardKey tvSatelliteToggle;

    static LogicalKeyboardKey tvTerrestrialAnalog;

    static LogicalKeyboardKey tvTerrestrialDigital;

    static LogicalKeyboardKey tvTimer;

    static LogicalKeyboardKey key11;

    static LogicalKeyboardKey key12;

    static LogicalKeyboardKey suspend;

    static LogicalKeyboardKey resume;

    static LogicalKeyboardKey sleep;

    static LogicalKeyboardKey abort;

    static LogicalKeyboardKey lang1;

    static LogicalKeyboardKey lang2;

    static LogicalKeyboardKey lang3;

    static LogicalKeyboardKey lang4;

    static LogicalKeyboardKey lang5;

    static LogicalKeyboardKey intlBackslash;

    static LogicalKeyboardKey intlRo;

    static LogicalKeyboardKey intlYen;

    static LogicalKeyboardKey controlLeft;

    static LogicalKeyboardKey controlRight;

    static LogicalKeyboardKey shiftLeft;

    static LogicalKeyboardKey shiftRight;

    static LogicalKeyboardKey altLeft;

    static LogicalKeyboardKey altRight;

    static LogicalKeyboardKey metaLeft;

    static LogicalKeyboardKey metaRight;

    static LogicalKeyboardKey control;

    static LogicalKeyboardKey shift;

    static LogicalKeyboardKey alt;

    static LogicalKeyboardKey meta;

    static LogicalKeyboardKey numpadEnter;

    static LogicalKeyboardKey numpadParenLeft;

    static LogicalKeyboardKey numpadParenRight;

    static LogicalKeyboardKey numpadMultiply;

    static LogicalKeyboardKey numpadAdd;

    static LogicalKeyboardKey numpadComma;

    static LogicalKeyboardKey numpadSubtract;

    static LogicalKeyboardKey numpadDecimal;

    static LogicalKeyboardKey numpadDivide;

    static LogicalKeyboardKey numpad0;

    static LogicalKeyboardKey numpad1;

    static LogicalKeyboardKey numpad2;

    static LogicalKeyboardKey numpad3;

    static LogicalKeyboardKey numpad4;

    static LogicalKeyboardKey numpad5;

    static LogicalKeyboardKey numpad6;

    static LogicalKeyboardKey numpad7;

    static LogicalKeyboardKey numpad8;

    static LogicalKeyboardKey numpad9;

    static LogicalKeyboardKey numpadEqual;

    static LogicalKeyboardKey gameButton1;

    static LogicalKeyboardKey gameButton2;

    static LogicalKeyboardKey gameButton3;

    static LogicalKeyboardKey gameButton4;

    static LogicalKeyboardKey gameButton5;

    static LogicalKeyboardKey gameButton6;

    static LogicalKeyboardKey gameButton7;

    static LogicalKeyboardKey gameButton8;

    static LogicalKeyboardKey gameButton9;

    static LogicalKeyboardKey gameButton10;

    static LogicalKeyboardKey gameButton11;

    static LogicalKeyboardKey gameButton12;

    static LogicalKeyboardKey gameButton13;

    static LogicalKeyboardKey gameButton14;

    static LogicalKeyboardKey gameButton15;

    static LogicalKeyboardKey gameButton16;

    static LogicalKeyboardKey gameButtonA;

    static LogicalKeyboardKey gameButtonB;

    static LogicalKeyboardKey gameButtonC;

    static LogicalKeyboardKey gameButtonLeft1;

    static LogicalKeyboardKey gameButtonLeft2;

    static LogicalKeyboardKey gameButtonMode;

    static LogicalKeyboardKey gameButtonRight1;

    static LogicalKeyboardKey gameButtonRight2;

    static LogicalKeyboardKey gameButtonSelect;

    static LogicalKeyboardKey gameButtonStart;

    static LogicalKeyboardKey gameButtonThumbLeft;

    static LogicalKeyboardKey gameButtonThumbRight;

    static LogicalKeyboardKey gameButtonX;

    static LogicalKeyboardKey gameButtonY;

    static LogicalKeyboardKey gameButtonZ;


     LogicalKeyboardKeyCls(int keyId);
    virtual String keyLabel();

    virtual String debugName();

    virtual int hashCode();

    virtual bool operator==(Object other);

    static LogicalKeyboardKey findKeyByKeyId(int keyId);

    static bool isControlCharacter(String label);

    virtual bool isAutogenerated();

    virtual Set<LogicalKeyboardKey> synonyms();

    static Set<LogicalKeyboardKey> collapseSynonyms(Set<LogicalKeyboardKey> input);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    static Iterable<LogicalKeyboardKey> knownLogicalKeys();

private:
    static Map<int, LogicalKeyboardKey> _knownLogicalKeys;

    static Map<LogicalKeyboardKey, LogicalKeyboardKey> _synonyms;

    static Map<int, String> _keyLabels;


    static int _nonValueBits(int n);

    static String _unicodeKeyLabel(int keyId);

};
using LogicalKeyboardKey = std::shared_ptr<LogicalKeyboardKeyCls>;

class PhysicalKeyboardKeyCls : public KeyboardKeyCls {
public:
    int usbHidUsage;

    static PhysicalKeyboardKey hyper;

    static PhysicalKeyboardKey superKey;

    static PhysicalKeyboardKey fn;

    static PhysicalKeyboardKey fnLock;

    static PhysicalKeyboardKey suspend;

    static PhysicalKeyboardKey resume;

    static PhysicalKeyboardKey turbo;

    static PhysicalKeyboardKey privacyScreenToggle;

    static PhysicalKeyboardKey microphoneMuteToggle;

    static PhysicalKeyboardKey sleep;

    static PhysicalKeyboardKey wakeUp;

    static PhysicalKeyboardKey displayToggleIntExt;

    static PhysicalKeyboardKey gameButton1;

    static PhysicalKeyboardKey gameButton2;

    static PhysicalKeyboardKey gameButton3;

    static PhysicalKeyboardKey gameButton4;

    static PhysicalKeyboardKey gameButton5;

    static PhysicalKeyboardKey gameButton6;

    static PhysicalKeyboardKey gameButton7;

    static PhysicalKeyboardKey gameButton8;

    static PhysicalKeyboardKey gameButton9;

    static PhysicalKeyboardKey gameButton10;

    static PhysicalKeyboardKey gameButton11;

    static PhysicalKeyboardKey gameButton12;

    static PhysicalKeyboardKey gameButton13;

    static PhysicalKeyboardKey gameButton14;

    static PhysicalKeyboardKey gameButton15;

    static PhysicalKeyboardKey gameButton16;

    static PhysicalKeyboardKey gameButtonA;

    static PhysicalKeyboardKey gameButtonB;

    static PhysicalKeyboardKey gameButtonC;

    static PhysicalKeyboardKey gameButtonLeft1;

    static PhysicalKeyboardKey gameButtonLeft2;

    static PhysicalKeyboardKey gameButtonMode;

    static PhysicalKeyboardKey gameButtonRight1;

    static PhysicalKeyboardKey gameButtonRight2;

    static PhysicalKeyboardKey gameButtonSelect;

    static PhysicalKeyboardKey gameButtonStart;

    static PhysicalKeyboardKey gameButtonThumbLeft;

    static PhysicalKeyboardKey gameButtonThumbRight;

    static PhysicalKeyboardKey gameButtonX;

    static PhysicalKeyboardKey gameButtonY;

    static PhysicalKeyboardKey gameButtonZ;

    static PhysicalKeyboardKey usbReserved;

    static PhysicalKeyboardKey usbErrorRollOver;

    static PhysicalKeyboardKey usbPostFail;

    static PhysicalKeyboardKey usbErrorUndefined;

    static PhysicalKeyboardKey keyA;

    static PhysicalKeyboardKey keyB;

    static PhysicalKeyboardKey keyC;

    static PhysicalKeyboardKey keyD;

    static PhysicalKeyboardKey keyE;

    static PhysicalKeyboardKey keyF;

    static PhysicalKeyboardKey keyG;

    static PhysicalKeyboardKey keyH;

    static PhysicalKeyboardKey keyI;

    static PhysicalKeyboardKey keyJ;

    static PhysicalKeyboardKey keyK;

    static PhysicalKeyboardKey keyL;

    static PhysicalKeyboardKey keyM;

    static PhysicalKeyboardKey keyN;

    static PhysicalKeyboardKey keyO;

    static PhysicalKeyboardKey keyP;

    static PhysicalKeyboardKey keyQ;

    static PhysicalKeyboardKey keyR;

    static PhysicalKeyboardKey keyS;

    static PhysicalKeyboardKey keyT;

    static PhysicalKeyboardKey keyU;

    static PhysicalKeyboardKey keyV;

    static PhysicalKeyboardKey keyW;

    static PhysicalKeyboardKey keyX;

    static PhysicalKeyboardKey keyY;

    static PhysicalKeyboardKey keyZ;

    static PhysicalKeyboardKey digit1;

    static PhysicalKeyboardKey digit2;

    static PhysicalKeyboardKey digit3;

    static PhysicalKeyboardKey digit4;

    static PhysicalKeyboardKey digit5;

    static PhysicalKeyboardKey digit6;

    static PhysicalKeyboardKey digit7;

    static PhysicalKeyboardKey digit8;

    static PhysicalKeyboardKey digit9;

    static PhysicalKeyboardKey digit0;

    static PhysicalKeyboardKey enter;

    static PhysicalKeyboardKey escape;

    static PhysicalKeyboardKey backspace;

    static PhysicalKeyboardKey tab;

    static PhysicalKeyboardKey space;

    static PhysicalKeyboardKey minus;

    static PhysicalKeyboardKey equal;

    static PhysicalKeyboardKey bracketLeft;

    static PhysicalKeyboardKey bracketRight;

    static PhysicalKeyboardKey backslash;

    static PhysicalKeyboardKey semicolon;

    static PhysicalKeyboardKey quote;

    static PhysicalKeyboardKey backquote;

    static PhysicalKeyboardKey comma;

    static PhysicalKeyboardKey period;

    static PhysicalKeyboardKey slash;

    static PhysicalKeyboardKey capsLock;

    static PhysicalKeyboardKey f1;

    static PhysicalKeyboardKey f2;

    static PhysicalKeyboardKey f3;

    static PhysicalKeyboardKey f4;

    static PhysicalKeyboardKey f5;

    static PhysicalKeyboardKey f6;

    static PhysicalKeyboardKey f7;

    static PhysicalKeyboardKey f8;

    static PhysicalKeyboardKey f9;

    static PhysicalKeyboardKey f10;

    static PhysicalKeyboardKey f11;

    static PhysicalKeyboardKey f12;

    static PhysicalKeyboardKey printScreen;

    static PhysicalKeyboardKey scrollLock;

    static PhysicalKeyboardKey pause;

    static PhysicalKeyboardKey insert;

    static PhysicalKeyboardKey home;

    static PhysicalKeyboardKey pageUp;

    static PhysicalKeyboardKey delete;

    static PhysicalKeyboardKey end;

    static PhysicalKeyboardKey pageDown;

    static PhysicalKeyboardKey arrowRight;

    static PhysicalKeyboardKey arrowLeft;

    static PhysicalKeyboardKey arrowDown;

    static PhysicalKeyboardKey arrowUp;

    static PhysicalKeyboardKey numLock;

    static PhysicalKeyboardKey numpadDivide;

    static PhysicalKeyboardKey numpadMultiply;

    static PhysicalKeyboardKey numpadSubtract;

    static PhysicalKeyboardKey numpadAdd;

    static PhysicalKeyboardKey numpadEnter;

    static PhysicalKeyboardKey numpad1;

    static PhysicalKeyboardKey numpad2;

    static PhysicalKeyboardKey numpad3;

    static PhysicalKeyboardKey numpad4;

    static PhysicalKeyboardKey numpad5;

    static PhysicalKeyboardKey numpad6;

    static PhysicalKeyboardKey numpad7;

    static PhysicalKeyboardKey numpad8;

    static PhysicalKeyboardKey numpad9;

    static PhysicalKeyboardKey numpad0;

    static PhysicalKeyboardKey numpadDecimal;

    static PhysicalKeyboardKey intlBackslash;

    static PhysicalKeyboardKey contextMenu;

    static PhysicalKeyboardKey power;

    static PhysicalKeyboardKey numpadEqual;

    static PhysicalKeyboardKey f13;

    static PhysicalKeyboardKey f14;

    static PhysicalKeyboardKey f15;

    static PhysicalKeyboardKey f16;

    static PhysicalKeyboardKey f17;

    static PhysicalKeyboardKey f18;

    static PhysicalKeyboardKey f19;

    static PhysicalKeyboardKey f20;

    static PhysicalKeyboardKey f21;

    static PhysicalKeyboardKey f22;

    static PhysicalKeyboardKey f23;

    static PhysicalKeyboardKey f24;

    static PhysicalKeyboardKey open;

    static PhysicalKeyboardKey help;

    static PhysicalKeyboardKey select;

    static PhysicalKeyboardKey again;

    static PhysicalKeyboardKey undo;

    static PhysicalKeyboardKey cut;

    static PhysicalKeyboardKey copy;

    static PhysicalKeyboardKey paste;

    static PhysicalKeyboardKey find;

    static PhysicalKeyboardKey audioVolumeMute;

    static PhysicalKeyboardKey audioVolumeUp;

    static PhysicalKeyboardKey audioVolumeDown;

    static PhysicalKeyboardKey numpadComma;

    static PhysicalKeyboardKey intlRo;

    static PhysicalKeyboardKey kanaMode;

    static PhysicalKeyboardKey intlYen;

    static PhysicalKeyboardKey convert;

    static PhysicalKeyboardKey nonConvert;

    static PhysicalKeyboardKey lang1;

    static PhysicalKeyboardKey lang2;

    static PhysicalKeyboardKey lang3;

    static PhysicalKeyboardKey lang4;

    static PhysicalKeyboardKey lang5;

    static PhysicalKeyboardKey abort;

    static PhysicalKeyboardKey props;

    static PhysicalKeyboardKey numpadParenLeft;

    static PhysicalKeyboardKey numpadParenRight;

    static PhysicalKeyboardKey numpadBackspace;

    static PhysicalKeyboardKey numpadMemoryStore;

    static PhysicalKeyboardKey numpadMemoryRecall;

    static PhysicalKeyboardKey numpadMemoryClear;

    static PhysicalKeyboardKey numpadMemoryAdd;

    static PhysicalKeyboardKey numpadMemorySubtract;

    static PhysicalKeyboardKey numpadSignChange;

    static PhysicalKeyboardKey numpadClear;

    static PhysicalKeyboardKey numpadClearEntry;

    static PhysicalKeyboardKey controlLeft;

    static PhysicalKeyboardKey shiftLeft;

    static PhysicalKeyboardKey altLeft;

    static PhysicalKeyboardKey metaLeft;

    static PhysicalKeyboardKey controlRight;

    static PhysicalKeyboardKey shiftRight;

    static PhysicalKeyboardKey altRight;

    static PhysicalKeyboardKey metaRight;

    static PhysicalKeyboardKey info;

    static PhysicalKeyboardKey closedCaptionToggle;

    static PhysicalKeyboardKey brightnessUp;

    static PhysicalKeyboardKey brightnessDown;

    static PhysicalKeyboardKey brightnessToggle;

    static PhysicalKeyboardKey brightnessMinimum;

    static PhysicalKeyboardKey brightnessMaximum;

    static PhysicalKeyboardKey brightnessAuto;

    static PhysicalKeyboardKey kbdIllumUp;

    static PhysicalKeyboardKey kbdIllumDown;

    static PhysicalKeyboardKey mediaLast;

    static PhysicalKeyboardKey launchPhone;

    static PhysicalKeyboardKey programGuide;

    static PhysicalKeyboardKey exit;

    static PhysicalKeyboardKey channelUp;

    static PhysicalKeyboardKey channelDown;

    static PhysicalKeyboardKey mediaPlay;

    static PhysicalKeyboardKey mediaPause;

    static PhysicalKeyboardKey mediaRecord;

    static PhysicalKeyboardKey mediaFastForward;

    static PhysicalKeyboardKey mediaRewind;

    static PhysicalKeyboardKey mediaTrackNext;

    static PhysicalKeyboardKey mediaTrackPrevious;

    static PhysicalKeyboardKey mediaStop;

    static PhysicalKeyboardKey eject;

    static PhysicalKeyboardKey mediaPlayPause;

    static PhysicalKeyboardKey speechInputToggle;

    static PhysicalKeyboardKey bassBoost;

    static PhysicalKeyboardKey mediaSelect;

    static PhysicalKeyboardKey launchWordProcessor;

    static PhysicalKeyboardKey launchSpreadsheet;

    static PhysicalKeyboardKey launchMail;

    static PhysicalKeyboardKey launchContacts;

    static PhysicalKeyboardKey launchCalendar;

    static PhysicalKeyboardKey launchApp2;

    static PhysicalKeyboardKey launchApp1;

    static PhysicalKeyboardKey launchInternetBrowser;

    static PhysicalKeyboardKey logOff;

    static PhysicalKeyboardKey lockScreen;

    static PhysicalKeyboardKey launchControlPanel;

    static PhysicalKeyboardKey selectTask;

    static PhysicalKeyboardKey launchDocuments;

    static PhysicalKeyboardKey spellCheck;

    static PhysicalKeyboardKey launchKeyboardLayout;

    static PhysicalKeyboardKey launchScreenSaver;

    static PhysicalKeyboardKey launchAudioBrowser;

    static PhysicalKeyboardKey launchAssistant;

    static PhysicalKeyboardKey newKey;

    static PhysicalKeyboardKey close;

    static PhysicalKeyboardKey save;

    static PhysicalKeyboardKey print;

    static PhysicalKeyboardKey browserSearch;

    static PhysicalKeyboardKey browserHome;

    static PhysicalKeyboardKey browserBack;

    static PhysicalKeyboardKey browserForward;

    static PhysicalKeyboardKey browserStop;

    static PhysicalKeyboardKey browserRefresh;

    static PhysicalKeyboardKey browserFavorites;

    static PhysicalKeyboardKey zoomIn;

    static PhysicalKeyboardKey zoomOut;

    static PhysicalKeyboardKey zoomToggle;

    static PhysicalKeyboardKey redo;

    static PhysicalKeyboardKey mailReply;

    static PhysicalKeyboardKey mailForward;

    static PhysicalKeyboardKey mailSend;

    static PhysicalKeyboardKey keyboardLayoutSelect;

    static PhysicalKeyboardKey showAllWindows;


     PhysicalKeyboardKeyCls(int usbHidUsage);
    virtual String debugName();

    virtual int hashCode();

    virtual bool operator==(Object other);

    static PhysicalKeyboardKey findKeyByCode(int usageCode);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    static Iterable<PhysicalKeyboardKey> knownPhysicalKeys();

private:
    static Map<int, PhysicalKeyboardKey> _knownPhysicalKeys;

    static Map<int, String> _debugNames;


};
using PhysicalKeyboardKey = std::shared_ptr<PhysicalKeyboardKeyCls>;


#endif