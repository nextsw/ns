#ifndef KEYBOARD_KEY.G_H
#define KEYBOARD_KEY.G_H
#include <memory>
#include <flutter/foundation.hpp>

#include <flutter/foundation.hpp>



class KeyboardKey {
public:

     KeyboardKey();

private:

};

class LogicalKeyboardKey : KeyboardKey {
public:
    int keyId;

    static const int valueMask;

    static const int planeMask;

    static const int unicodePlane;

    static const int unprintablePlane;

    static const int flutterPlane;

    static const int startOfPlatformPlanes;

    static const int androidPlane;

    static const int fuchsiaPlane;

    static const int iosPlane;

    static const int macosPlane;

    static const int gtkPlane;

    static const int windowsPlane;

    static const int webPlane;

    static const int glfwPlane;

    static const LogicalKeyboardKey space;

    static const LogicalKeyboardKey exclamation;

    static const LogicalKeyboardKey quote;

    static const LogicalKeyboardKey numberSign;

    static const LogicalKeyboardKey dollar;

    static const LogicalKeyboardKey percent;

    static const LogicalKeyboardKey ampersand;

    static const LogicalKeyboardKey quoteSingle;

    static const LogicalKeyboardKey parenthesisLeft;

    static const LogicalKeyboardKey parenthesisRight;

    static const LogicalKeyboardKey asterisk;

    static const LogicalKeyboardKey add;

    static const LogicalKeyboardKey comma;

    static const LogicalKeyboardKey minus;

    static const LogicalKeyboardKey period;

    static const LogicalKeyboardKey slash;

    static const LogicalKeyboardKey digit0;

    static const LogicalKeyboardKey digit1;

    static const LogicalKeyboardKey digit2;

    static const LogicalKeyboardKey digit3;

    static const LogicalKeyboardKey digit4;

    static const LogicalKeyboardKey digit5;

    static const LogicalKeyboardKey digit6;

    static const LogicalKeyboardKey digit7;

    static const LogicalKeyboardKey digit8;

    static const LogicalKeyboardKey digit9;

    static const LogicalKeyboardKey colon;

    static const LogicalKeyboardKey semicolon;

    static const LogicalKeyboardKey less;

    static const LogicalKeyboardKey equal;

    static const LogicalKeyboardKey greater;

    static const LogicalKeyboardKey question;

    static const LogicalKeyboardKey at;

    static const LogicalKeyboardKey bracketLeft;

    static const LogicalKeyboardKey backslash;

    static const LogicalKeyboardKey bracketRight;

    static const LogicalKeyboardKey caret;

    static const LogicalKeyboardKey underscore;

    static const LogicalKeyboardKey backquote;

    static const LogicalKeyboardKey keyA;

    static const LogicalKeyboardKey keyB;

    static const LogicalKeyboardKey keyC;

    static const LogicalKeyboardKey keyD;

    static const LogicalKeyboardKey keyE;

    static const LogicalKeyboardKey keyF;

    static const LogicalKeyboardKey keyG;

    static const LogicalKeyboardKey keyH;

    static const LogicalKeyboardKey keyI;

    static const LogicalKeyboardKey keyJ;

    static const LogicalKeyboardKey keyK;

    static const LogicalKeyboardKey keyL;

    static const LogicalKeyboardKey keyM;

    static const LogicalKeyboardKey keyN;

    static const LogicalKeyboardKey keyO;

    static const LogicalKeyboardKey keyP;

    static const LogicalKeyboardKey keyQ;

    static const LogicalKeyboardKey keyR;

    static const LogicalKeyboardKey keyS;

    static const LogicalKeyboardKey keyT;

    static const LogicalKeyboardKey keyU;

    static const LogicalKeyboardKey keyV;

    static const LogicalKeyboardKey keyW;

    static const LogicalKeyboardKey keyX;

    static const LogicalKeyboardKey keyY;

    static const LogicalKeyboardKey keyZ;

    static const LogicalKeyboardKey braceLeft;

    static const LogicalKeyboardKey bar;

    static const LogicalKeyboardKey braceRight;

    static const LogicalKeyboardKey tilde;

    static const LogicalKeyboardKey unidentified;

    static const LogicalKeyboardKey backspace;

    static const LogicalKeyboardKey tab;

    static const LogicalKeyboardKey enter;

    static const LogicalKeyboardKey escape;

    static const LogicalKeyboardKey delete;

    static const LogicalKeyboardKey accel;

    static const LogicalKeyboardKey altGraph;

    static const LogicalKeyboardKey capsLock;

    static const LogicalKeyboardKey fn;

    static const LogicalKeyboardKey fnLock;

    static const LogicalKeyboardKey hyper;

    static const LogicalKeyboardKey numLock;

    static const LogicalKeyboardKey scrollLock;

    static const LogicalKeyboardKey superKey;

    static const LogicalKeyboardKey symbol;

    static const LogicalKeyboardKey symbolLock;

    static const LogicalKeyboardKey shiftLevel5;

    static const LogicalKeyboardKey arrowDown;

    static const LogicalKeyboardKey arrowLeft;

    static const LogicalKeyboardKey arrowRight;

    static const LogicalKeyboardKey arrowUp;

    static const LogicalKeyboardKey end;

    static const LogicalKeyboardKey home;

    static const LogicalKeyboardKey pageDown;

    static const LogicalKeyboardKey pageUp;

    static const LogicalKeyboardKey clear;

    static const LogicalKeyboardKey copy;

    static const LogicalKeyboardKey crSel;

    static const LogicalKeyboardKey cut;

    static const LogicalKeyboardKey eraseEof;

    static const LogicalKeyboardKey exSel;

    static const LogicalKeyboardKey insert;

    static const LogicalKeyboardKey paste;

    static const LogicalKeyboardKey redo;

    static const LogicalKeyboardKey undo;

    static const LogicalKeyboardKey accept;

    static const LogicalKeyboardKey again;

    static const LogicalKeyboardKey attn;

    static const LogicalKeyboardKey cancel;

    static const LogicalKeyboardKey contextMenu;

    static const LogicalKeyboardKey execute;

    static const LogicalKeyboardKey find;

    static const LogicalKeyboardKey help;

    static const LogicalKeyboardKey pause;

    static const LogicalKeyboardKey play;

    static const LogicalKeyboardKey props;

    static const LogicalKeyboardKey select;

    static const LogicalKeyboardKey zoomIn;

    static const LogicalKeyboardKey zoomOut;

    static const LogicalKeyboardKey brightnessDown;

    static const LogicalKeyboardKey brightnessUp;

    static const LogicalKeyboardKey camera;

    static const LogicalKeyboardKey eject;

    static const LogicalKeyboardKey logOff;

    static const LogicalKeyboardKey power;

    static const LogicalKeyboardKey powerOff;

    static const LogicalKeyboardKey printScreen;

    static const LogicalKeyboardKey hibernate;

    static const LogicalKeyboardKey standby;

    static const LogicalKeyboardKey wakeUp;

    static const LogicalKeyboardKey allCandidates;

    static const LogicalKeyboardKey alphanumeric;

    static const LogicalKeyboardKey codeInput;

    static const LogicalKeyboardKey compose;

    static const LogicalKeyboardKey convert;

    static const LogicalKeyboardKey finalMode;

    static const LogicalKeyboardKey groupFirst;

    static const LogicalKeyboardKey groupLast;

    static const LogicalKeyboardKey groupNext;

    static const LogicalKeyboardKey groupPrevious;

    static const LogicalKeyboardKey modeChange;

    static const LogicalKeyboardKey nextCandidate;

    static const LogicalKeyboardKey nonConvert;

    static const LogicalKeyboardKey previousCandidate;

    static const LogicalKeyboardKey process;

    static const LogicalKeyboardKey singleCandidate;

    static const LogicalKeyboardKey hangulMode;

    static const LogicalKeyboardKey hanjaMode;

    static const LogicalKeyboardKey junjaMode;

    static const LogicalKeyboardKey eisu;

    static const LogicalKeyboardKey hankaku;

    static const LogicalKeyboardKey hiragana;

    static const LogicalKeyboardKey hiraganaKatakana;

    static const LogicalKeyboardKey kanaMode;

    static const LogicalKeyboardKey kanjiMode;

    static const LogicalKeyboardKey katakana;

    static const LogicalKeyboardKey romaji;

    static const LogicalKeyboardKey zenkaku;

    static const LogicalKeyboardKey zenkakuHankaku;

    static const LogicalKeyboardKey f1;

    static const LogicalKeyboardKey f2;

    static const LogicalKeyboardKey f3;

    static const LogicalKeyboardKey f4;

    static const LogicalKeyboardKey f5;

    static const LogicalKeyboardKey f6;

    static const LogicalKeyboardKey f7;

    static const LogicalKeyboardKey f8;

    static const LogicalKeyboardKey f9;

    static const LogicalKeyboardKey f10;

    static const LogicalKeyboardKey f11;

    static const LogicalKeyboardKey f12;

    static const LogicalKeyboardKey f13;

    static const LogicalKeyboardKey f14;

    static const LogicalKeyboardKey f15;

    static const LogicalKeyboardKey f16;

    static const LogicalKeyboardKey f17;

    static const LogicalKeyboardKey f18;

    static const LogicalKeyboardKey f19;

    static const LogicalKeyboardKey f20;

    static const LogicalKeyboardKey f21;

    static const LogicalKeyboardKey f22;

    static const LogicalKeyboardKey f23;

    static const LogicalKeyboardKey f24;

    static const LogicalKeyboardKey soft1;

    static const LogicalKeyboardKey soft2;

    static const LogicalKeyboardKey soft3;

    static const LogicalKeyboardKey soft4;

    static const LogicalKeyboardKey soft5;

    static const LogicalKeyboardKey soft6;

    static const LogicalKeyboardKey soft7;

    static const LogicalKeyboardKey soft8;

    static const LogicalKeyboardKey close;

    static const LogicalKeyboardKey mailForward;

    static const LogicalKeyboardKey mailReply;

    static const LogicalKeyboardKey mailSend;

    static const LogicalKeyboardKey mediaPlayPause;

    static const LogicalKeyboardKey mediaStop;

    static const LogicalKeyboardKey mediaTrackNext;

    static const LogicalKeyboardKey mediaTrackPrevious;

    static const LogicalKeyboardKey newKey;

    static const LogicalKeyboardKey open;

    static const LogicalKeyboardKey print;

    static const LogicalKeyboardKey save;

    static const LogicalKeyboardKey spellCheck;

    static const LogicalKeyboardKey audioVolumeDown;

    static const LogicalKeyboardKey audioVolumeUp;

    static const LogicalKeyboardKey audioVolumeMute;

    static const LogicalKeyboardKey launchApplication2;

    static const LogicalKeyboardKey launchCalendar;

    static const LogicalKeyboardKey launchMail;

    static const LogicalKeyboardKey launchMediaPlayer;

    static const LogicalKeyboardKey launchMusicPlayer;

    static const LogicalKeyboardKey launchApplication1;

    static const LogicalKeyboardKey launchScreenSaver;

    static const LogicalKeyboardKey launchSpreadsheet;

    static const LogicalKeyboardKey launchWebBrowser;

    static const LogicalKeyboardKey launchWebCam;

    static const LogicalKeyboardKey launchWordProcessor;

    static const LogicalKeyboardKey launchContacts;

    static const LogicalKeyboardKey launchPhone;

    static const LogicalKeyboardKey launchAssistant;

    static const LogicalKeyboardKey launchControlPanel;

    static const LogicalKeyboardKey browserBack;

    static const LogicalKeyboardKey browserFavorites;

    static const LogicalKeyboardKey browserForward;

    static const LogicalKeyboardKey browserHome;

    static const LogicalKeyboardKey browserRefresh;

    static const LogicalKeyboardKey browserSearch;

    static const LogicalKeyboardKey browserStop;

    static const LogicalKeyboardKey audioBalanceLeft;

    static const LogicalKeyboardKey audioBalanceRight;

    static const LogicalKeyboardKey audioBassBoostDown;

    static const LogicalKeyboardKey audioBassBoostUp;

    static const LogicalKeyboardKey audioFaderFront;

    static const LogicalKeyboardKey audioFaderRear;

    static const LogicalKeyboardKey audioSurroundModeNext;

    static const LogicalKeyboardKey avrInput;

    static const LogicalKeyboardKey avrPower;

    static const LogicalKeyboardKey channelDown;

    static const LogicalKeyboardKey channelUp;

    static const LogicalKeyboardKey colorF0Red;

    static const LogicalKeyboardKey colorF1Green;

    static const LogicalKeyboardKey colorF2Yellow;

    static const LogicalKeyboardKey colorF3Blue;

    static const LogicalKeyboardKey colorF4Grey;

    static const LogicalKeyboardKey colorF5Brown;

    static const LogicalKeyboardKey closedCaptionToggle;

    static const LogicalKeyboardKey dimmer;

    static const LogicalKeyboardKey displaySwap;

    static const LogicalKeyboardKey exit;

    static const LogicalKeyboardKey favoriteClear0;

    static const LogicalKeyboardKey favoriteClear1;

    static const LogicalKeyboardKey favoriteClear2;

    static const LogicalKeyboardKey favoriteClear3;

    static const LogicalKeyboardKey favoriteRecall0;

    static const LogicalKeyboardKey favoriteRecall1;

    static const LogicalKeyboardKey favoriteRecall2;

    static const LogicalKeyboardKey favoriteRecall3;

    static const LogicalKeyboardKey favoriteStore0;

    static const LogicalKeyboardKey favoriteStore1;

    static const LogicalKeyboardKey favoriteStore2;

    static const LogicalKeyboardKey favoriteStore3;

    static const LogicalKeyboardKey guide;

    static const LogicalKeyboardKey guideNextDay;

    static const LogicalKeyboardKey guidePreviousDay;

    static const LogicalKeyboardKey info;

    static const LogicalKeyboardKey instantReplay;

    static const LogicalKeyboardKey link;

    static const LogicalKeyboardKey listProgram;

    static const LogicalKeyboardKey liveContent;

    static const LogicalKeyboardKey lock;

    static const LogicalKeyboardKey mediaApps;

    static const LogicalKeyboardKey mediaFastForward;

    static const LogicalKeyboardKey mediaLast;

    static const LogicalKeyboardKey mediaPause;

    static const LogicalKeyboardKey mediaPlay;

    static const LogicalKeyboardKey mediaRecord;

    static const LogicalKeyboardKey mediaRewind;

    static const LogicalKeyboardKey mediaSkip;

    static const LogicalKeyboardKey nextFavoriteChannel;

    static const LogicalKeyboardKey nextUserProfile;

    static const LogicalKeyboardKey onDemand;

    static const LogicalKeyboardKey pInPDown;

    static const LogicalKeyboardKey pInPMove;

    static const LogicalKeyboardKey pInPToggle;

    static const LogicalKeyboardKey pInPUp;

    static const LogicalKeyboardKey playSpeedDown;

    static const LogicalKeyboardKey playSpeedReset;

    static const LogicalKeyboardKey playSpeedUp;

    static const LogicalKeyboardKey randomToggle;

    static const LogicalKeyboardKey rcLowBattery;

    static const LogicalKeyboardKey recordSpeedNext;

    static const LogicalKeyboardKey rfBypass;

    static const LogicalKeyboardKey scanChannelsToggle;

    static const LogicalKeyboardKey screenModeNext;

    static const LogicalKeyboardKey settings;

    static const LogicalKeyboardKey splitScreenToggle;

    static const LogicalKeyboardKey stbInput;

    static const LogicalKeyboardKey stbPower;

    static const LogicalKeyboardKey subtitle;

    static const LogicalKeyboardKey teletext;

    static const LogicalKeyboardKey tv;

    static const LogicalKeyboardKey tvInput;

    static const LogicalKeyboardKey tvPower;

    static const LogicalKeyboardKey videoModeNext;

    static const LogicalKeyboardKey wink;

    static const LogicalKeyboardKey zoomToggle;

    static const LogicalKeyboardKey dvr;

    static const LogicalKeyboardKey mediaAudioTrack;

    static const LogicalKeyboardKey mediaSkipBackward;

    static const LogicalKeyboardKey mediaSkipForward;

    static const LogicalKeyboardKey mediaStepBackward;

    static const LogicalKeyboardKey mediaStepForward;

    static const LogicalKeyboardKey mediaTopMenu;

    static const LogicalKeyboardKey navigateIn;

    static const LogicalKeyboardKey navigateNext;

    static const LogicalKeyboardKey navigateOut;

    static const LogicalKeyboardKey navigatePrevious;

    static const LogicalKeyboardKey pairing;

    static const LogicalKeyboardKey mediaClose;

    static const LogicalKeyboardKey audioBassBoostToggle;

    static const LogicalKeyboardKey audioTrebleDown;

    static const LogicalKeyboardKey audioTrebleUp;

    static const LogicalKeyboardKey microphoneToggle;

    static const LogicalKeyboardKey microphoneVolumeDown;

    static const LogicalKeyboardKey microphoneVolumeUp;

    static const LogicalKeyboardKey microphoneVolumeMute;

    static const LogicalKeyboardKey speechCorrectionList;

    static const LogicalKeyboardKey speechInputToggle;

    static const LogicalKeyboardKey appSwitch;

    static const LogicalKeyboardKey call;

    static const LogicalKeyboardKey cameraFocus;

    static const LogicalKeyboardKey endCall;

    static const LogicalKeyboardKey goBack;

    static const LogicalKeyboardKey goHome;

    static const LogicalKeyboardKey headsetHook;

    static const LogicalKeyboardKey lastNumberRedial;

    static const LogicalKeyboardKey notification;

    static const LogicalKeyboardKey mannerMode;

    static const LogicalKeyboardKey voiceDial;

    static const LogicalKeyboardKey tv3DMode;

    static const LogicalKeyboardKey tvAntennaCable;

    static const LogicalKeyboardKey tvAudioDescription;

    static const LogicalKeyboardKey tvAudioDescriptionMixDown;

    static const LogicalKeyboardKey tvAudioDescriptionMixUp;

    static const LogicalKeyboardKey tvContentsMenu;

    static const LogicalKeyboardKey tvDataService;

    static const LogicalKeyboardKey tvInputComponent1;

    static const LogicalKeyboardKey tvInputComponent2;

    static const LogicalKeyboardKey tvInputComposite1;

    static const LogicalKeyboardKey tvInputComposite2;

    static const LogicalKeyboardKey tvInputHDMI1;

    static const LogicalKeyboardKey tvInputHDMI2;

    static const LogicalKeyboardKey tvInputHDMI3;

    static const LogicalKeyboardKey tvInputHDMI4;

    static const LogicalKeyboardKey tvInputVGA1;

    static const LogicalKeyboardKey tvMediaContext;

    static const LogicalKeyboardKey tvNetwork;

    static const LogicalKeyboardKey tvNumberEntry;

    static const LogicalKeyboardKey tvRadioService;

    static const LogicalKeyboardKey tvSatellite;

    static const LogicalKeyboardKey tvSatelliteBS;

    static const LogicalKeyboardKey tvSatelliteCS;

    static const LogicalKeyboardKey tvSatelliteToggle;

    static const LogicalKeyboardKey tvTerrestrialAnalog;

    static const LogicalKeyboardKey tvTerrestrialDigital;

    static const LogicalKeyboardKey tvTimer;

    static const LogicalKeyboardKey key11;

    static const LogicalKeyboardKey key12;

    static const LogicalKeyboardKey suspend;

    static const LogicalKeyboardKey resume;

    static const LogicalKeyboardKey sleep;

    static const LogicalKeyboardKey abort;

    static const LogicalKeyboardKey lang1;

    static const LogicalKeyboardKey lang2;

    static const LogicalKeyboardKey lang3;

    static const LogicalKeyboardKey lang4;

    static const LogicalKeyboardKey lang5;

    static const LogicalKeyboardKey intlBackslash;

    static const LogicalKeyboardKey intlRo;

    static const LogicalKeyboardKey intlYen;

    static const LogicalKeyboardKey controlLeft;

    static const LogicalKeyboardKey controlRight;

    static const LogicalKeyboardKey shiftLeft;

    static const LogicalKeyboardKey shiftRight;

    static const LogicalKeyboardKey altLeft;

    static const LogicalKeyboardKey altRight;

    static const LogicalKeyboardKey metaLeft;

    static const LogicalKeyboardKey metaRight;

    static const LogicalKeyboardKey control;

    static const LogicalKeyboardKey shift;

    static const LogicalKeyboardKey alt;

    static const LogicalKeyboardKey meta;

    static const LogicalKeyboardKey numpadEnter;

    static const LogicalKeyboardKey numpadParenLeft;

    static const LogicalKeyboardKey numpadParenRight;

    static const LogicalKeyboardKey numpadMultiply;

    static const LogicalKeyboardKey numpadAdd;

    static const LogicalKeyboardKey numpadComma;

    static const LogicalKeyboardKey numpadSubtract;

    static const LogicalKeyboardKey numpadDecimal;

    static const LogicalKeyboardKey numpadDivide;

    static const LogicalKeyboardKey numpad0;

    static const LogicalKeyboardKey numpad1;

    static const LogicalKeyboardKey numpad2;

    static const LogicalKeyboardKey numpad3;

    static const LogicalKeyboardKey numpad4;

    static const LogicalKeyboardKey numpad5;

    static const LogicalKeyboardKey numpad6;

    static const LogicalKeyboardKey numpad7;

    static const LogicalKeyboardKey numpad8;

    static const LogicalKeyboardKey numpad9;

    static const LogicalKeyboardKey numpadEqual;

    static const LogicalKeyboardKey gameButton1;

    static const LogicalKeyboardKey gameButton2;

    static const LogicalKeyboardKey gameButton3;

    static const LogicalKeyboardKey gameButton4;

    static const LogicalKeyboardKey gameButton5;

    static const LogicalKeyboardKey gameButton6;

    static const LogicalKeyboardKey gameButton7;

    static const LogicalKeyboardKey gameButton8;

    static const LogicalKeyboardKey gameButton9;

    static const LogicalKeyboardKey gameButton10;

    static const LogicalKeyboardKey gameButton11;

    static const LogicalKeyboardKey gameButton12;

    static const LogicalKeyboardKey gameButton13;

    static const LogicalKeyboardKey gameButton14;

    static const LogicalKeyboardKey gameButton15;

    static const LogicalKeyboardKey gameButton16;

    static const LogicalKeyboardKey gameButtonA;

    static const LogicalKeyboardKey gameButtonB;

    static const LogicalKeyboardKey gameButtonC;

    static const LogicalKeyboardKey gameButtonLeft1;

    static const LogicalKeyboardKey gameButtonLeft2;

    static const LogicalKeyboardKey gameButtonMode;

    static const LogicalKeyboardKey gameButtonRight1;

    static const LogicalKeyboardKey gameButtonRight2;

    static const LogicalKeyboardKey gameButtonSelect;

    static const LogicalKeyboardKey gameButtonStart;

    static const LogicalKeyboardKey gameButtonThumbLeft;

    static const LogicalKeyboardKey gameButtonThumbRight;

    static const LogicalKeyboardKey gameButtonX;

    static const LogicalKeyboardKey gameButtonY;

    static const LogicalKeyboardKey gameButtonZ;


     LogicalKeyboardKey(int keyId);

    String keyLabel();

    String debugName();

    int hashCode();

    bool ==(Object other);

    static LogicalKeyboardKey findKeyByKeyId(int keyId);

    static bool isControlCharacter(String label);

    bool isAutogenerated();

    Set<LogicalKeyboardKey> synonyms();

    static Set<LogicalKeyboardKey> collapseSynonyms(Set<LogicalKeyboardKey> input);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    static Iterable<LogicalKeyboardKey> knownLogicalKeys();

private:
    static const Map<int, LogicalKeyboardKey> _knownLogicalKeys;

    static Map<LogicalKeyboardKey, LogicalKeyboardKey> _synonyms;

    static const Map<int, String> _keyLabels;


    static int _nonValueBits(int n);

    static String _unicodeKeyLabel(int keyId);

};

class PhysicalKeyboardKey : KeyboardKey {
public:
    int usbHidUsage;

    static const PhysicalKeyboardKey hyper;

    static const PhysicalKeyboardKey superKey;

    static const PhysicalKeyboardKey fn;

    static const PhysicalKeyboardKey fnLock;

    static const PhysicalKeyboardKey suspend;

    static const PhysicalKeyboardKey resume;

    static const PhysicalKeyboardKey turbo;

    static const PhysicalKeyboardKey privacyScreenToggle;

    static const PhysicalKeyboardKey microphoneMuteToggle;

    static const PhysicalKeyboardKey sleep;

    static const PhysicalKeyboardKey wakeUp;

    static const PhysicalKeyboardKey displayToggleIntExt;

    static const PhysicalKeyboardKey gameButton1;

    static const PhysicalKeyboardKey gameButton2;

    static const PhysicalKeyboardKey gameButton3;

    static const PhysicalKeyboardKey gameButton4;

    static const PhysicalKeyboardKey gameButton5;

    static const PhysicalKeyboardKey gameButton6;

    static const PhysicalKeyboardKey gameButton7;

    static const PhysicalKeyboardKey gameButton8;

    static const PhysicalKeyboardKey gameButton9;

    static const PhysicalKeyboardKey gameButton10;

    static const PhysicalKeyboardKey gameButton11;

    static const PhysicalKeyboardKey gameButton12;

    static const PhysicalKeyboardKey gameButton13;

    static const PhysicalKeyboardKey gameButton14;

    static const PhysicalKeyboardKey gameButton15;

    static const PhysicalKeyboardKey gameButton16;

    static const PhysicalKeyboardKey gameButtonA;

    static const PhysicalKeyboardKey gameButtonB;

    static const PhysicalKeyboardKey gameButtonC;

    static const PhysicalKeyboardKey gameButtonLeft1;

    static const PhysicalKeyboardKey gameButtonLeft2;

    static const PhysicalKeyboardKey gameButtonMode;

    static const PhysicalKeyboardKey gameButtonRight1;

    static const PhysicalKeyboardKey gameButtonRight2;

    static const PhysicalKeyboardKey gameButtonSelect;

    static const PhysicalKeyboardKey gameButtonStart;

    static const PhysicalKeyboardKey gameButtonThumbLeft;

    static const PhysicalKeyboardKey gameButtonThumbRight;

    static const PhysicalKeyboardKey gameButtonX;

    static const PhysicalKeyboardKey gameButtonY;

    static const PhysicalKeyboardKey gameButtonZ;

    static const PhysicalKeyboardKey usbReserved;

    static const PhysicalKeyboardKey usbErrorRollOver;

    static const PhysicalKeyboardKey usbPostFail;

    static const PhysicalKeyboardKey usbErrorUndefined;

    static const PhysicalKeyboardKey keyA;

    static const PhysicalKeyboardKey keyB;

    static const PhysicalKeyboardKey keyC;

    static const PhysicalKeyboardKey keyD;

    static const PhysicalKeyboardKey keyE;

    static const PhysicalKeyboardKey keyF;

    static const PhysicalKeyboardKey keyG;

    static const PhysicalKeyboardKey keyH;

    static const PhysicalKeyboardKey keyI;

    static const PhysicalKeyboardKey keyJ;

    static const PhysicalKeyboardKey keyK;

    static const PhysicalKeyboardKey keyL;

    static const PhysicalKeyboardKey keyM;

    static const PhysicalKeyboardKey keyN;

    static const PhysicalKeyboardKey keyO;

    static const PhysicalKeyboardKey keyP;

    static const PhysicalKeyboardKey keyQ;

    static const PhysicalKeyboardKey keyR;

    static const PhysicalKeyboardKey keyS;

    static const PhysicalKeyboardKey keyT;

    static const PhysicalKeyboardKey keyU;

    static const PhysicalKeyboardKey keyV;

    static const PhysicalKeyboardKey keyW;

    static const PhysicalKeyboardKey keyX;

    static const PhysicalKeyboardKey keyY;

    static const PhysicalKeyboardKey keyZ;

    static const PhysicalKeyboardKey digit1;

    static const PhysicalKeyboardKey digit2;

    static const PhysicalKeyboardKey digit3;

    static const PhysicalKeyboardKey digit4;

    static const PhysicalKeyboardKey digit5;

    static const PhysicalKeyboardKey digit6;

    static const PhysicalKeyboardKey digit7;

    static const PhysicalKeyboardKey digit8;

    static const PhysicalKeyboardKey digit9;

    static const PhysicalKeyboardKey digit0;

    static const PhysicalKeyboardKey enter;

    static const PhysicalKeyboardKey escape;

    static const PhysicalKeyboardKey backspace;

    static const PhysicalKeyboardKey tab;

    static const PhysicalKeyboardKey space;

    static const PhysicalKeyboardKey minus;

    static const PhysicalKeyboardKey equal;

    static const PhysicalKeyboardKey bracketLeft;

    static const PhysicalKeyboardKey bracketRight;

    static const PhysicalKeyboardKey backslash;

    static const PhysicalKeyboardKey semicolon;

    static const PhysicalKeyboardKey quote;

    static const PhysicalKeyboardKey backquote;

    static const PhysicalKeyboardKey comma;

    static const PhysicalKeyboardKey period;

    static const PhysicalKeyboardKey slash;

    static const PhysicalKeyboardKey capsLock;

    static const PhysicalKeyboardKey f1;

    static const PhysicalKeyboardKey f2;

    static const PhysicalKeyboardKey f3;

    static const PhysicalKeyboardKey f4;

    static const PhysicalKeyboardKey f5;

    static const PhysicalKeyboardKey f6;

    static const PhysicalKeyboardKey f7;

    static const PhysicalKeyboardKey f8;

    static const PhysicalKeyboardKey f9;

    static const PhysicalKeyboardKey f10;

    static const PhysicalKeyboardKey f11;

    static const PhysicalKeyboardKey f12;

    static const PhysicalKeyboardKey printScreen;

    static const PhysicalKeyboardKey scrollLock;

    static const PhysicalKeyboardKey pause;

    static const PhysicalKeyboardKey insert;

    static const PhysicalKeyboardKey home;

    static const PhysicalKeyboardKey pageUp;

    static const PhysicalKeyboardKey delete;

    static const PhysicalKeyboardKey end;

    static const PhysicalKeyboardKey pageDown;

    static const PhysicalKeyboardKey arrowRight;

    static const PhysicalKeyboardKey arrowLeft;

    static const PhysicalKeyboardKey arrowDown;

    static const PhysicalKeyboardKey arrowUp;

    static const PhysicalKeyboardKey numLock;

    static const PhysicalKeyboardKey numpadDivide;

    static const PhysicalKeyboardKey numpadMultiply;

    static const PhysicalKeyboardKey numpadSubtract;

    static const PhysicalKeyboardKey numpadAdd;

    static const PhysicalKeyboardKey numpadEnter;

    static const PhysicalKeyboardKey numpad1;

    static const PhysicalKeyboardKey numpad2;

    static const PhysicalKeyboardKey numpad3;

    static const PhysicalKeyboardKey numpad4;

    static const PhysicalKeyboardKey numpad5;

    static const PhysicalKeyboardKey numpad6;

    static const PhysicalKeyboardKey numpad7;

    static const PhysicalKeyboardKey numpad8;

    static const PhysicalKeyboardKey numpad9;

    static const PhysicalKeyboardKey numpad0;

    static const PhysicalKeyboardKey numpadDecimal;

    static const PhysicalKeyboardKey intlBackslash;

    static const PhysicalKeyboardKey contextMenu;

    static const PhysicalKeyboardKey power;

    static const PhysicalKeyboardKey numpadEqual;

    static const PhysicalKeyboardKey f13;

    static const PhysicalKeyboardKey f14;

    static const PhysicalKeyboardKey f15;

    static const PhysicalKeyboardKey f16;

    static const PhysicalKeyboardKey f17;

    static const PhysicalKeyboardKey f18;

    static const PhysicalKeyboardKey f19;

    static const PhysicalKeyboardKey f20;

    static const PhysicalKeyboardKey f21;

    static const PhysicalKeyboardKey f22;

    static const PhysicalKeyboardKey f23;

    static const PhysicalKeyboardKey f24;

    static const PhysicalKeyboardKey open;

    static const PhysicalKeyboardKey help;

    static const PhysicalKeyboardKey select;

    static const PhysicalKeyboardKey again;

    static const PhysicalKeyboardKey undo;

    static const PhysicalKeyboardKey cut;

    static const PhysicalKeyboardKey copy;

    static const PhysicalKeyboardKey paste;

    static const PhysicalKeyboardKey find;

    static const PhysicalKeyboardKey audioVolumeMute;

    static const PhysicalKeyboardKey audioVolumeUp;

    static const PhysicalKeyboardKey audioVolumeDown;

    static const PhysicalKeyboardKey numpadComma;

    static const PhysicalKeyboardKey intlRo;

    static const PhysicalKeyboardKey kanaMode;

    static const PhysicalKeyboardKey intlYen;

    static const PhysicalKeyboardKey convert;

    static const PhysicalKeyboardKey nonConvert;

    static const PhysicalKeyboardKey lang1;

    static const PhysicalKeyboardKey lang2;

    static const PhysicalKeyboardKey lang3;

    static const PhysicalKeyboardKey lang4;

    static const PhysicalKeyboardKey lang5;

    static const PhysicalKeyboardKey abort;

    static const PhysicalKeyboardKey props;

    static const PhysicalKeyboardKey numpadParenLeft;

    static const PhysicalKeyboardKey numpadParenRight;

    static const PhysicalKeyboardKey numpadBackspace;

    static const PhysicalKeyboardKey numpadMemoryStore;

    static const PhysicalKeyboardKey numpadMemoryRecall;

    static const PhysicalKeyboardKey numpadMemoryClear;

    static const PhysicalKeyboardKey numpadMemoryAdd;

    static const PhysicalKeyboardKey numpadMemorySubtract;

    static const PhysicalKeyboardKey numpadSignChange;

    static const PhysicalKeyboardKey numpadClear;

    static const PhysicalKeyboardKey numpadClearEntry;

    static const PhysicalKeyboardKey controlLeft;

    static const PhysicalKeyboardKey shiftLeft;

    static const PhysicalKeyboardKey altLeft;

    static const PhysicalKeyboardKey metaLeft;

    static const PhysicalKeyboardKey controlRight;

    static const PhysicalKeyboardKey shiftRight;

    static const PhysicalKeyboardKey altRight;

    static const PhysicalKeyboardKey metaRight;

    static const PhysicalKeyboardKey info;

    static const PhysicalKeyboardKey closedCaptionToggle;

    static const PhysicalKeyboardKey brightnessUp;

    static const PhysicalKeyboardKey brightnessDown;

    static const PhysicalKeyboardKey brightnessToggle;

    static const PhysicalKeyboardKey brightnessMinimum;

    static const PhysicalKeyboardKey brightnessMaximum;

    static const PhysicalKeyboardKey brightnessAuto;

    static const PhysicalKeyboardKey kbdIllumUp;

    static const PhysicalKeyboardKey kbdIllumDown;

    static const PhysicalKeyboardKey mediaLast;

    static const PhysicalKeyboardKey launchPhone;

    static const PhysicalKeyboardKey programGuide;

    static const PhysicalKeyboardKey exit;

    static const PhysicalKeyboardKey channelUp;

    static const PhysicalKeyboardKey channelDown;

    static const PhysicalKeyboardKey mediaPlay;

    static const PhysicalKeyboardKey mediaPause;

    static const PhysicalKeyboardKey mediaRecord;

    static const PhysicalKeyboardKey mediaFastForward;

    static const PhysicalKeyboardKey mediaRewind;

    static const PhysicalKeyboardKey mediaTrackNext;

    static const PhysicalKeyboardKey mediaTrackPrevious;

    static const PhysicalKeyboardKey mediaStop;

    static const PhysicalKeyboardKey eject;

    static const PhysicalKeyboardKey mediaPlayPause;

    static const PhysicalKeyboardKey speechInputToggle;

    static const PhysicalKeyboardKey bassBoost;

    static const PhysicalKeyboardKey mediaSelect;

    static const PhysicalKeyboardKey launchWordProcessor;

    static const PhysicalKeyboardKey launchSpreadsheet;

    static const PhysicalKeyboardKey launchMail;

    static const PhysicalKeyboardKey launchContacts;

    static const PhysicalKeyboardKey launchCalendar;

    static const PhysicalKeyboardKey launchApp2;

    static const PhysicalKeyboardKey launchApp1;

    static const PhysicalKeyboardKey launchInternetBrowser;

    static const PhysicalKeyboardKey logOff;

    static const PhysicalKeyboardKey lockScreen;

    static const PhysicalKeyboardKey launchControlPanel;

    static const PhysicalKeyboardKey selectTask;

    static const PhysicalKeyboardKey launchDocuments;

    static const PhysicalKeyboardKey spellCheck;

    static const PhysicalKeyboardKey launchKeyboardLayout;

    static const PhysicalKeyboardKey launchScreenSaver;

    static const PhysicalKeyboardKey launchAudioBrowser;

    static const PhysicalKeyboardKey launchAssistant;

    static const PhysicalKeyboardKey newKey;

    static const PhysicalKeyboardKey close;

    static const PhysicalKeyboardKey save;

    static const PhysicalKeyboardKey print;

    static const PhysicalKeyboardKey browserSearch;

    static const PhysicalKeyboardKey browserHome;

    static const PhysicalKeyboardKey browserBack;

    static const PhysicalKeyboardKey browserForward;

    static const PhysicalKeyboardKey browserStop;

    static const PhysicalKeyboardKey browserRefresh;

    static const PhysicalKeyboardKey browserFavorites;

    static const PhysicalKeyboardKey zoomIn;

    static const PhysicalKeyboardKey zoomOut;

    static const PhysicalKeyboardKey zoomToggle;

    static const PhysicalKeyboardKey redo;

    static const PhysicalKeyboardKey mailReply;

    static const PhysicalKeyboardKey mailForward;

    static const PhysicalKeyboardKey mailSend;

    static const PhysicalKeyboardKey keyboardLayoutSelect;

    static const PhysicalKeyboardKey showAllWindows;


     PhysicalKeyboardKey(int usbHidUsage);

    String debugName();

    int hashCode();

    bool ==(Object other);

    static PhysicalKeyboardKey findKeyByCode(int usageCode);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    static Iterable<PhysicalKeyboardKey> knownPhysicalKeys();

private:
    static const Map<int, PhysicalKeyboardKey> _knownPhysicalKeys;

    static const Map<int, String> _debugNames;


};

#endif