#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QWidget>
#include <QPushButton>
#include <QtCore>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QMenuBar>
#include <QToolButton>
#include <QStatusBar>
#include <QLabel>
#include <QFontDialog>
#include <string>
#include <iostream>
#include <QSizePolicy>
#include "borderlayout.h"
#include "canvas.h"
#include "mode.h"
#include "elementChosen.h"


/**
 * @brief The ElementChosen enum
 *
 * This enum is for the Window class to use mainly.
 * It contains all of the items that can be added to the canvas.
 */
enum class ElementChosen
{
	NONE, STRAIGHTH, STRAIGHTV, STRAIGHTLEFTUP, STRIAGHTRIGHTUP, DIRECTLEFT, DIRECTRIGHT, DIRECTUP, DIRECTDOWN, DIRECTRIGHTUP,
	DIRECTLEFTUP, DIRECTLEFTDOWN, DIRECTRIGHTDOWN, TIGHTCURVE1, TIGHTCURVE2, TIGHTCURVE3, TIGHTCURVE4, CURVE1, CURVE2, CURVE3,
	CURVE4, CURVE5, CURVE6, CURVE7, CURVE8, LINKLEFT, LINKRIGHT, LINKDOWN, LINKUP, LINKLEFTUP, LINKRIGHTUP, LINKLEFTDOWN,
	LINKRIGHTDOWN, EXITLEFT, EXITRIGHT, EXITDOWN, EXITUP, EXITLEFTUP, EXITRIGHTUP, EXITLEFTDOWN, EXITRIGHTDOWN, BUFFERLEFT, BUFFERRIGHT,
	BUFFERDOWN, BUFFERUP, BUFFERLEFTUP, BUFFERRIGHTUP, BUFFERLEFTDOWN, BUFFERRIGHTDOWN, SIGNALLEFT, SIGNALRIGHT, SIGNALDOWN, SIGNALUP,
	SIGNALLEFTUP, SIGNALRIGHTUP, SIGNALLEFTDOWN, SIGNALRIGHTDOWN, BRIDGE1, BRIDGE2, UNDERPASS1, UNDERPASS2, SWITCHTIGHT1,
	SWITCHTIGHT2, SWITCHTIGHT3, SWITCHTIGHT4, SWITCHTIGHT5, SWITCHTIGHT6, SWITCHTIGHT7, SWITCHTIGHT8, SWITCHSPLIT1, SWITCHSPLIT2,
	SWITCHSPLIT3, SWITCHSPLIT4, SWITCHSPLIT5, SWITCHSPLIT6, SWITCHSPLIT7, SWITCHSPLIT8, SWITCH1, SWITCH2, SWITCH3, SWITCH4, SWITCH5,
	SWITCH6, SWITCH7, SWITCH8, SWITCH9, SWITCH10, SWITCH11, SWITCH12, SWITCH13, SWITCH14, SWITCH15, SWITCH16, CROSSOVER1,
	CROSSOVER2, CROSSOVER3, CROSSOVER4, CROSSOVER5, CROSSOVER6, FLYOVER1, FLYOVER2, FLYOVER3, FLYOVER4, FLYOVER5, FLYOVER6,
	FLYOVER7, FLYOVER8, FLYOVER9, FLYOVER10, FLYOVER11, FLYOVER12, NAMEDLOCATION, CONCOURSE, PLATFORMLEFT, PLATFORMRIGHT,
	PLATFORMDOWN, PLATFORMUP, PARAPET1, PARAPET2, PARAPET3, PARAPET4, PARAPET5, PARAPET6, PARAPET7, PARAPET8, PARAPET9,
	PARAPET10, PARAPET11, PARAPET12, PARAPET13, PARAPET14, PARAPET15, PARAPET16, PARAPET17, PARAPET18, PARAPET19, PARAPET20,
	PARAPET21, PARAPET22, PARAPET23, PARAPET24, PARAPET25, PARAPET26, PARAPET27, PARAPET28, LEVELCROSSING
	//, ADDCHANGETEXT, MOVETEXT,
	//SETCHANGENAMEDLOCATION, CONNECTLINKEDTRACK, SETTRACKLENGTHSPEED

};


/**
 * @brief The Mode enum
 *
 * This enum is for the Window class to use mainly.
 * It contains all of the modes, that are possible in the program.
 */

enum class Mode
{
	NONE, ADDREMOVETRACK

};



/**
 * @brief The Window class for making the entire GUI for the program.
 *
 * @author Jonathan Kwok
 * @version 0.1
 */
class Window : public QWidget
{
	Q_OBJECT

public:
	/**
	 * @brief A constructor for a Window object that extends the QWidget.
	 * Create a window object that includes the different parts needed to make the program function like the Canvas and the BorderLayout.
	 */
	Window();
	~Window();

private slots:
	/**
	 * @brief A slot to open the element menu to place elements on screen.
	 */
	void openElementMenu();

	/**
	 * @brief A slot to select StraightH tracks to place on screen.
	 */
	void chooseStraightH();



private:
	/**
	 * @brief A method to create the menubar that is at the top of the screen.
	 *
	 * Currently only addes a File and Mode menu.
	 * @version 0.1
	 */
	void createMenuBar();

	/**
	 * @brief A method to create the overall menu of the program.
	 */
	void createOverallMenu();

	/**
	 * @brief A method to create the menu that is shown after the Build/Modify Railway is pressed in the menubar.
	 */
	void createBuildModifyMenu();

	/**
	 * @brief A method to create the menu where the user can choose track type.
	 */
	void createElementMenu();

	/**
	 * @brief A method to create the part 1 of the element buttons where the user can choose track type.
	 */
	void createElementBlock1();

	QMenuBar *menuBar;
	QMenu *fileMenu;
	QMenu *modeMenu;


	Mode mode;
	ElementChosen elementChosenToPlace;
	QWidget *top1Menu;

	QHBoxLayout *buildModifyMenu1;
	QToolButton *elementMenuButton;
	QIcon   *elementMenuIcon;
	QAction *openElementMenuAct;

	QStackedWidget *allMenus;

	QWidget *elementMenu;
	QGridLayout* elementMenuLayout;

	QToolButton *straightHButton;
	QIcon *straightHIcon;
	QAction *chooseStraightHAct;

};
#endif // WINDOW_H
