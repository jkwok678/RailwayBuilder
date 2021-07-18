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

void Window::chooseStraightH()
{
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
	top1Menu = new QWidget();
	buildModifyMenu1 = new QHBoxLayout;
	QPalette pal2 = palette();
	pal2.setColor(QPalette::Window, Qt::red);
	top1Menu->setAutoFillBackground(true);
	top1Menu->setPalette(pal2);
	top1Menu->setLayout(buildModifyMenu1);

	createBuildModifyMenu();


	allMenus = new QStackedWidget;
	createElementMenu();
	allMenus->addWidget(new QWidget());
	allMenus->addWidget(elementMenu);
	allMenus->setCurrentIndex(0);

}
void Window::createBuildModifyMenu()
{
	elementMenuButton = new QToolButton();
	elementMenuButton->setMaximumSize(QSize(32,32));
	openElementMenuAct = new QAction;
	elementMenuButton->setDefaultAction(openElementMenuAct);
	connect(openElementMenuAct,&QAction::triggered,this,&Window::openElementMenu);
	elementMenuIcon = new QIcon(":/icons/icons/buildMenuIcon.png");
	elementMenuButton->setIcon(*elementMenuIcon);
	buildModifyMenu1->addWidget(elementMenuButton);

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
