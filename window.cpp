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

	converterGrid1 = new QGridLayout;
	milesLabel = new QLabel;
	milesLabel->setText(tr("Miles"));
	milesEntry = new QLineEdit;
	milesEntry->setMaximumWidth(100);
	chainsLabel = new QLabel;
	chainsLabel->setText(tr("chains"));
	chainsEntry = new QLineEdit;
	chainsEntry->setMaximumWidth(100);
	yardsLabel = new QLabel;
	yardsLabel->setText(tr("Yards"));
	yardsEntry = new QLineEdit;
	yardsEntry->setMaximumWidth(100);
	metresLabel = new QLabel;
	metresLabel->setText(tr("Metres"));
	actualMetres = new QLineEdit;
	actualMetres->setMaximumWidth(100);
	actualMetres->setReadOnly(true);
	actualMetres->setDisabled(true);

	//connect(milesEntry, &QLineEdit::textChanged, this, &Window::convertMilesYardMetres);
	//connect(yardsEntry, &QLineEdit::textChanged, this, &Window::convertMilesYardMetres);

	converterGrid1->addWidget(milesLabel,0,1);
	converterGrid1->addWidget(milesEntry,0,0);
	converterGrid1->addWidget(chainsLabel,1,1);
	converterGrid1->addWidget(chainsEntry,1,0);
	converterGrid1->addWidget(yardsLabel,2,1);
	converterGrid1->addWidget(yardsEntry,2,0);

	converterGrid1->addWidget(metresLabel,0,2);
	converterGrid1->addWidget(actualMetres,1,2);

	converterGrid2 = new QGridLayout;
	speedLabel1 = new QLabel;
	speedLabel1->setText(tr("mph"));
	speedEntry1 = new QLineEdit;

	speedEntry1->setMaximumWidth(150);
	swapLabelButton = new QPushButton;
	swapLabelButton->setText(tr("Swap"));
	swapLabelButton->setMinimumWidth(30);
	swapLabelButton->setMaximumWidth(75);
	connect(swapLabelButton, SIGNAL (released()),this, SLOT (swapSpeedLabel()));
	speedLabel2 = new QLabel;
	speedLabel2->setText(tr("km/h"));
	speedResult = new QLineEdit;
	speedResult->setMaximumWidth(150);
	speedResult->setDisabled(true);
	//connect(speedEntry1, &QLineEdit::textChanged, this, &Window::convertMPHKMH);

	converterGrid2->addWidget(speedLabel1,0,0);
	converterGrid2->addWidget(speedEntry1,1,0);
	converterGrid2->addWidget(speedLabel2,2,0);
	converterGrid2->addWidget(swapLabelButton,2,1);
	converterGrid2->addWidget(speedResult,3,0);
	converterGrid2->setVerticalSpacing(1);


	//setTrackLengthSpeedLayout1->addLayout(converterGrid);
	//setTrackLengthSpeedLayout1->setAlignment(converterGrid, Qt::AlignLeft);

	setConvertSpeedDistanceHLayout->addLayout(converterGrid1);
	setConvertSpeedDistanceHLayout->addLayout(converterGrid2);
}
