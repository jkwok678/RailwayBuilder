#include "window.h"

Window::Window()
{
	Canvas *centralWidget = new Canvas;
	createMenuBar();
	createOverallMenu();
	mode = Mode::NONE;
	BorderLayout *layout = new BorderLayout;
	layout->addWidget(menuBar,BorderLayout::North);
	layout->addWidget(top1Menu,BorderLayout::North);
	layout->addWidget(allMenus,BorderLayout::North);
	layout->addWidget(centralWidget, BorderLayout::Center);
	setLayout(layout);
}

Window::~Window()
{
}

void Window::openElementMenu()
{
	//Set the QStackWidget to the AddMoveTrack menu if it isn't on there yet.
	//If it is, then go back to the start.
	if (allMenus->currentIndex() != 1)
	{
		allMenus->setCurrentIndex(1);
		mode = Mode::ADDREMOVETRACK;
	}
	else
	{
		allMenus->setCurrentIndex(0);
		mode = Mode::NONE;
	}

}

void Window::openSetConvertSpeedDistanceMenu()
{
	//Set the QStackWidget to the setConvertSpeedDistance menu if it isn't on there yet.
	//If it is, then go back to the start.
	if (allMenus->currentIndex() != 2)
	{
		allMenus->setCurrentIndex(2);
		mode = Mode::SETCONVERTSPEEDDISTANCE;
	}
	else
	{
		allMenus->setCurrentIndex(0);
		mode = Mode::NONE;
	}
}

void Window::chooseStraightH()
{
	//If the Mode is AddRemoveTrack and the element is StraightH,
	// the element to add will be a Straight horizontal.
	//Otherwise set to nothing.
	if (mode==Mode::ADDREMOVETRACK && elementChosenToPlace != ElementChosen::STRAIGHTH)
	{
		elementChosenToPlace = ElementChosen::STRAIGHTH;
	}
	else
	{
		elementChosenToPlace = ElementChosen::NONE;
	}
}

void Window::createMenuBar()
{
	menuBar = new QMenuBar();
	fileMenu = new QMenu("File");
	modeMenu = new QMenu("Mode");
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(modeMenu);
}

void Window::createOverallMenu()
{
	//Create the whole menu widget.
	top1Menu = new QWidget();
	//Add a layout.
	buildModifyMenu1 = new QHBoxLayout;
	QPalette pal2 = palette();
	pal2.setColor(QPalette::Window, Qt::red);
	top1Menu->setAutoFillBackground(true);
	top1Menu->setPalette(pal2);
	top1Menu->setLayout(buildModifyMenu1);

	//Create the different parts of it.
	createBuildModifyMenu();

	//Add all of the created menus back to the QStackedWidget.
	allMenus = new QStackedWidget;
	allMenus->addWidget(new QWidget());
	allMenus->addWidget(elementMenu);
	allMenus->addWidget(setConvertSpeedDistanceMenu);
	allMenus->setCurrentIndex(0);

}

void Window::createBuildModifyMenu()
{
	//Add the button to bring up the menu that allows the user to choose something to add to screen.
	elementMenuButton = new QToolButton();
	elementMenuButton->setMaximumSize(QSize(32,32));
	openElementMenuAct = new QAction;
	elementMenuButton->setDefaultAction(openElementMenuAct);
	connect(openElementMenuAct,&QAction::triggered,this,&Window::openElementMenu);
	elementMenuIcon = new QIcon(":/icons/icons/buildMenuIcon.png");
	elementMenuButton->setIcon(*elementMenuIcon);
	buildModifyMenu1->addWidget(elementMenuButton);

	//Add the button to bring up the menu that allows the user to set and convert speed and distances.
	setConvertSpeedDistanceMenuButton = new QToolButton();
	setConvertSpeedDistanceMenuButton->setMaximumSize(QSize(32,32));
	openSetConvertSpeedDistanceMenuAct = new QAction;
	setConvertSpeedDistanceMenuButton->setDefaultAction(openSetConvertSpeedDistanceMenuAct);
	connect(openSetConvertSpeedDistanceMenuAct,&QAction::triggered,this,&Window::openSetConvertSpeedDistanceMenu);
	setConvertSpeedDistanceMenuIcon = new QIcon(":/icons/icons/setDistanceSpeed.png");
	setConvertSpeedDistanceMenuButton->setIcon(*setConvertSpeedDistanceMenuIcon);
	buildModifyMenu1->addWidget(setConvertSpeedDistanceMenuButton);

	//Make part 2 of the menus.
	//These menus will be on the QStackedWidget.
	//The user will be able to choose which one comes up.
	createElementMenu();
	createSetConvertSpeedDistanceMenu();
}

void Window::createElementMenu()
{
	elementMenu = new QWidget;
	QPalette pal = palette();
	pal.setColor(QPalette::Window, Qt::green);
	elementMenu->setAutoFillBackground(true);
	elementMenu->setPalette(pal);
	elementMenuLayout = new QGridLayout;
	elementMenu->setLayout(elementMenuLayout);
	createElementBlock1();
}

void Window::createElementBlock1()
{
	straightHButton = new QToolButton();
	straightHButton->setMaximumSize(QSize(32, 32));
	chooseStraightHAct = new QAction();
	straightHButton->setDefaultAction(chooseStraightHAct);
	connect(chooseStraightHAct, &QAction::triggered, this, &Window::chooseStraightH);
	straightHIcon = new QIcon(":/graphics/graphics/straightH.png");
	straightHButton->setIcon(*straightHIcon);
	elementMenuLayout->addWidget(straightHButton, 0, 0);
}

void Window::createSetConvertSpeedDistanceMenu()
{
	setConvertSpeedDistanceMenu = new QWidget;
	setConvertSpeedDistanceHLayout = new QHBoxLayout;
	setConvertSpeedDistanceMenu->setLayout(setConvertSpeedDistanceHLayout);


	keyGraphicImage = new QLabel;
	keyImage = new QImage(":/icons/icons/keyGraphic.png");
	keyGraphicImage->setPixmap(QPixmap::fromImage(*keyImage));
	keyGraphicImage->setScaledContents(true);
	keyGraphicImage->setMaximumHeight(120);
	keyGraphicImage->setMaximumWidth(500);
	setConvertSpeedDistanceHLayout->addWidget(keyGraphicImage);

}
