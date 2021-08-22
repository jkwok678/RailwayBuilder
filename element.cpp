#include "element.h"


//Element class implementation.


Element::Element()
{

}

Element::Element(int currentX, int currentY)
{
	locationX = currentX;
	locationY = currentY;
}

int Element::getLocationX() const
{
	return locationX;
}

void Element::setLocationX(int newLocationX)
{
	locationX = newLocationX;
}

int Element::getLocationY() const
{
	return locationY;
}

void Element::setLocationY(int newLocationY)
{
	locationY = newLocationY;
}


//Text class implementation.


Text::Text(int newLocationX, int newLocationY, QString newReadableText, QFont newFont)
{
	locationX = newLocationX;
	locationY = newLocationY;
	readableText = newReadableText;
	editableX = locationX + fontSize;
	editableY = locationY + fontSize;
	font = newFont;
}

int Text::getEditableX() const
{
	return editableX;
}

void Text::setEditableX(int newEditableX)
{
	editableX = newEditableX;
}

int Text::getEditableY() const
{
	return editableY;
}

void Text::setEditableY(int newEditableY)
{
	editableY = newEditableY;
}

int Text::getFontSize() const
{
	return fontSize;
}

void Text::setFontSize(int newFontSize)
{
	fontSize = newFontSize;
}

QString Text::getReadableText() const
{
	return readableText;
}

void Text::setReadableText(const QString& newReadableText)
{
	readableText = newReadableText;
}

QFont Text::getFont() const
{
	return font;
}

void Text::setFont(const QFont newFont)
{
	font = newFont;
}


//NamedElement class implementation.


NamedElement::NamedElement()
{

}

bool NamedElement::getNamed() const
{
	return named;
}

void NamedElement::setNamed(bool newNamed)
{
	named = newNamed;
}

std::shared_ptr<Text> NamedElement::getText()
{
	return text;
}

void NamedElement::setText(std::shared_ptr<Text> &newText)
{
	text = newText;
}


//NamedLocation class implementation.


NamedLocation::NamedLocation(int newLocationX, int newLocationY)
{
	locationX = newLocationX;
	locationY = newLocationY;
	named = false;
	text = nullptr;


}


//Concourse class implementation.


Concourse::Concourse(int newLocationX, int newLocationY)
{
	locationX = newLocationX;
	locationY = newLocationY;
	named = false;
	text = nullptr;

}

//Parapet class implementation.

Parapet::Parapet(ParapetType newParapetType, int newLocationX, int newLocationY)
{
	parapetType = newParapetType;
	locationX = newLocationX;
	locationY = newLocationY;
}

ParapetType Parapet::getParapetType() const
{
	return parapetType;
}

void Parapet::setParapetType(const ParapetType &newParapetType)
{
	parapetType = newParapetType;
}
