#include "window.h"

//Public

Window::Window()
{
	drawingArea = new Canvas;
	createMenuBar();
	createOverallMenu();
	createRightDirectionalMenu();
	mode = Mode::NONE;
	BorderLayout *layout = new BorderLayout;
	layout->addWidget(menuBar,BorderLayout::North);
	layout->addWidget(top1Menu,BorderLayout::North);
	layout->addWidget(allMenus,BorderLayout::North);
	layout->addWidget(drawingArea, BorderLayout::Center);
	layout->addWidget(rightDirectionalMenu, BorderLayout::East);
	setLayout(layout);
}

Window::~Window()
{

}

int Window::convertDistances()
{
	/* If the miles text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make miles = 0.
	 */
	double miles,chains,yards;
	if (!milesEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = milesEntry->text().toDouble(&ok);
		if (ok)
		{
			 miles = tempD;
		}
	}
	else
	{
		miles = 0;
	}

	/* If the chains text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make chains = 0.
	 */
	if (!chainsEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = chainsEntry->text().toDouble(&ok);
		if (ok)
		{
			 chains = tempD;
		}
	}
	else
	{
		chains = 0;
	}
	/* If the yards text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make yards = 0.
	 */
	if (!yardsEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = yardsEntry->text().toDouble(&ok);
		if (ok)
		{
			 yards = tempD;
		}
	}
	else
	{
		yards = 0;
	}
	//Calculate miles + chains + yards in metres.
	int metres = round((miles* MILE_FACTOR) +(chains* CHAIN_FACTOR) + (yards* YARD_FACTOR));
	metres = std::ceil(metres * 100.0) / 100.0;
	return metres;
}

double Window::convertDistances(double miles, double chains, double yards)
{
	double resultM = convertMilesToMetres(miles);
	double resultC = convertChainsToMetres(chains);
	double resultY = convertYardsToMetres(yards);
	double metres = resultM + resultC + resultY;
	//* 100.0) / 100.0;
	return metres;
}

int Window::convertSpeed()
{
	//Convert mph to kmh or vice versa
	double result;
	double temp;
	//If a speed is entered, try convert it to a double.
	bool ok = false;
	double tempD = speedEntry1->text().toDouble(&ok);
	if (ok)
	{
		temp = tempD;
	}
	if (mphToKmh)
	{
		result = temp * MPH_TO_KMPH;
	}
	else
	{
		result = temp / MPH_TO_KMPH;
	}
	//Round up the result and display it.
	result = std::round(result * 100.0) / 100.0;
	return result;

}

double Window::convertSpeed(double speed)
{
	//Convert mph to kmh or vice versa
	double result;
	if (mphToKmh)
	{
		result = convertMPHToKMPH(speed);
	}
	else
	{
		result = convertKMPHToMPH(speed);
	}
	//Round up the result.
	result = std::ceil(result * 100.0) / 100.0;
	return result;
}


//private slots

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

void Window::updateMilesChainsYardsToMetresGUI()
{

	//Display it to user
	double miles = getMilesFromGUIToConvert();
	double chains = getChainsFromGUIToConvert();
	double yards = getYardsFromGUIToConvert();
	double metres = convertDistances(miles,chains,yards);
	actualMetres->setText(QString::number(metres));
}

void Window::swapSpeedLabel()
{
	//Swap the 2 texts on the labels
	//Then reconvert the numbers
	QString temp = speedLabel1->text();
	speedLabel1->setText(speedLabel2->text());
	speedLabel2->setText(temp);
	if (mphToKmh)
	{
		mphToKmh = false;
	}
	else
	{
		mphToKmh = true;
	}
	updateMPHKMHGUI();
}

void Window::updateMPHKMHGUI()
{
	double speed = getSpeedFromGUIToConvert();
	int result = convertSpeed(speed);
	if (!speedEntry1->text().isEmpty())
	{
		speedResult->setText(QString::number(result));
	}
	else
	{
		speedResult->setText("");
	}

}

//Element menu to choose element

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

//Right hand side menu.

void Window::moveRightOnCanvas()
{
	drawingArea->offsetMoveRight();
	std::cout << drawingArea->getOffsetX() << std::flush;
}

void Window::moveLeftOnCanvas()
{
	drawingArea->offsetMoveLeft();
	std::cout << drawingArea->getOffsetX() << std::flush;
}

void Window::moveUpOnCanvas()
{
	drawingArea->offsetMoveUp();
	std::cout << drawingArea->getOffsetY() << std::flush;
}

void Window::moveDownOnCanvas()
{
	drawingArea->offsetMoveDown();
	std::cout << drawingArea->getOffsetY() << std::flush;
}

//Private

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

	//Element Menu

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

	//SetConvertSpeedDistanceMenu

void Window::createSetConvertSpeedDistanceMenu()
{
	//Overall
	setConvertSpeedDistanceMenu = new QWidget;
	setConvertSpeedDistanceHLayout = new QHBoxLayout;
	setConvertSpeedDistanceMenu->setLayout(setConvertSpeedDistanceHLayout);

	//Converting distances menu.
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
	milesEntry->setMaximumWidth(120);
	chainsLabel = new QLabel;
	chainsLabel->setText(tr("chains"));
	chainsEntry = new QLineEdit;
	chainsEntry->setMaximumWidth(120);
	yardsLabel = new QLabel;
	yardsLabel->setText(tr("Yards"));
	yardsEntry = new QLineEdit;
	yardsEntry->setMaximumWidth(120);
	metresLabel = new QLabel;
	metresLabel->setText(tr("Metres"));
	actualMetres = new QLineEdit;
	actualMetres->setMaximumWidth(120);
	actualMetres->setReadOnly(true);
	actualMetres->setDisabled(true);

	connect(milesEntry, &QLineEdit::textChanged, this, &Window::updateMilesChainsYardsToMetresGUI);
	connect(chainsEntry, &QLineEdit::textChanged, this, &Window::updateMilesChainsYardsToMetresGUI);
	connect(yardsEntry, &QLineEdit::textChanged, this, &Window::updateMilesChainsYardsToMetresGUI);

	converterGrid1->addWidget(milesLabel,0,1);
	converterGrid1->addWidget(milesEntry,0,0);
	converterGrid1->addWidget(chainsLabel,1,1);
	converterGrid1->addWidget(chainsEntry,1,0);
	converterGrid1->addWidget(yardsLabel,2,1);
	converterGrid1->addWidget(yardsEntry,2,0);

	converterGrid1->addWidget(metresLabel,0,2);
	converterGrid1->addWidget(actualMetres,1,2);

	//Converting speed menu.
	converterGrid2 = new QGridLayout;
	speedLabel1 = new QLabel;
	speedLabel1->setText(tr("mph"));
	speedEntry1 = new QLineEdit;

	speedEntry1->setMaximumWidth(120);
	swapLabelButton = new QPushButton;
	swapLabelButton->setText(tr("Swap"));
	swapLabelButton->setMinimumWidth(30);
	swapLabelButton->setMaximumWidth(75);
	connect(swapLabelButton, SIGNAL (released()),this, SLOT (swapSpeedLabel()));
	speedLabel2 = new QLabel;
	speedLabel2->setText(tr("km/h"));
	speedResult = new QLineEdit;
	speedResult->setMaximumWidth(120);
	speedResult->setDisabled(true);
	connect(speedEntry1, &QLineEdit::textChanged, this, &Window::updateMPHKMHGUI);

	converterGrid2->addWidget(speedLabel1,0,0);
	converterGrid2->addWidget(speedEntry1,1,0);
	converterGrid2->addWidget(speedLabel2,2,0);
	converterGrid2->addWidget(swapLabelButton,2,1);
	converterGrid2->addWidget(speedResult,3,0);
	converterGrid2->setVerticalSpacing(1);


	setConvertSpeedDistanceHLayout->setAlignment(converterGrid2, Qt::AlignLeft);

	setConvertSpeedDistanceHLayout->addLayout(converterGrid1);
	setConvertSpeedDistanceHLayout->addLayout(converterGrid2);
}

double Window::getMilesFromGUIToConvert()
{
	/* If the miles text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make miles = 0.
	 */
	double miles = 0;
	if (!milesEntry->text().isEmpty())
	{

		bool ok = false;
		double tempD = milesEntry->text().toDouble(&ok);
		if (ok)
		{
			 miles = tempD;
		}
	}
	return miles;
}

double Window::getChainsFromGUIToConvert()
{
	/* If the chains text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make chains = 0.
	 */
	double chains = 0;
	if (!chainsEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = chainsEntry->text().toDouble(&ok);
		if (ok)
		{
			 chains = tempD;
		}
	}
	return chains;
}

double Window::getYardsFromGUIToConvert()
{
	/* If the yards text entry isn't empty, try make it a double.
	 * Then make it equal to the double that was inputted by the user.
	 * Otherwise make yards = 0.
	 */
	double yards = 0;
	if (!yardsEntry->text().isEmpty())
	{
		bool ok = false;
		double tempD = yardsEntry->text().toDouble(&ok);
		if (ok)
		{
			 yards = tempD;
		}
	}
	return yards;
}

double Window::getSpeedFromGUIToConvert()
{
	double speed = 0;

	if (!speedEntry1->text().isEmpty())
	{
		bool ok = false;
		//If a speed is entered, try convert it to a double.
		double tempD = speedEntry1->text().toDouble(&ok);
		if (ok)
		{
			speed = tempD;
		}
	}
	return speed;
}

double Window::convertMilesToMetres(double miles)
{
	return miles * MILE_FACTOR;
}

double Window::convertChainsToMetres(double chains)
{
	return chains * CHAIN_FACTOR;
}

double Window::convertYardsToMetres(double yards)
{
	return yards * YARD_FACTOR;
}

double Window::convertMPHToKMPH(double mph)
{
	return mph * MPH_TO_KMPH;
}

double Window::convertKMPHToMPH(double kmph)
{
	return kmph / MPH_TO_KMPH;
}

	//Right side directional menu.

void Window::createRightDirectionalMenu()
{
	rightDirectionalMenu = new QWidget;

	rightDirectionalMenuLayout = new QVBoxLayout;
	rightDirectionalMenu->setLayout(rightDirectionalMenuLayout);

	canvasMoveRightButton = new QToolButton();
	canvasMoveRightButton->setMaximumSize(QSize(32, 32));
	canvasMoveRightAct = new QAction();
	canvasMoveRightButton->setDefaultAction(canvasMoveRightAct);
	connect(canvasMoveRightAct, &QAction::triggered, this, &Window::moveRightOnCanvas);
	canvasMoveRightIcon = new QIcon(":/icons/icons/right.png");
	canvasMoveRightButton->setIcon(*canvasMoveRightIcon);
	rightDirectionalMenuLayout->addWidget(canvasMoveRightButton);

	canvasMoveLeftButton = new QToolButton();
	canvasMoveLeftButton->setMaximumSize(QSize(32, 32));
	canvasMoveLeftAct = new QAction();
	canvasMoveLeftButton->setDefaultAction(canvasMoveLeftAct);
	connect(canvasMoveLeftAct, &QAction::triggered, this, &Window::moveLeftOnCanvas);
	canvasMoveLeftIcon = new QIcon(":/icons/icons/left.png");
	canvasMoveLeftButton->setIcon(*canvasMoveLeftIcon);
	rightDirectionalMenuLayout->addWidget(canvasMoveLeftButton);

	canvasMoveUpButton = new QToolButton();
	canvasMoveUpButton->setMaximumSize(QSize(32, 32));
	canvasMoveUpAct = new QAction();
	canvasMoveUpButton->setDefaultAction(canvasMoveUpAct);
	connect(canvasMoveUpAct, &QAction::triggered, this, &Window::moveUpOnCanvas);
	canvasMoveUpIcon = new QIcon(":/icons/icons/up.png");
	canvasMoveUpButton->setIcon(*canvasMoveUpIcon);
	rightDirectionalMenuLayout->addWidget(canvasMoveUpButton);

	canvasMoveDownButton = new QToolButton();
	canvasMoveDownButton->setMaximumSize(QSize(32, 32));
	canvasMoveDownAct = new QAction();
	canvasMoveDownButton->setDefaultAction(canvasMoveDownAct);
	connect(canvasMoveDownAct, &QAction::triggered, this, &Window::moveDownOnCanvas);
	canvasMoveDownIcon = new QIcon(":/icons/icons/down.png");
	canvasMoveDownButton->setIcon(*canvasMoveDownIcon);
	rightDirectionalMenuLayout->addWidget(canvasMoveDownButton);
}
