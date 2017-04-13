#include "Menu.h"


//CONSTRUCTOR
Menu::Menu()
{
}

//CONSTRUCTOR W/ LAYER
Menu::Menu(DrawLayer & _layer, unsigned int _x, unsigned int _y, unsigned int _width) {
	layer = &_layer;
	textArr = new sf::Text[MAX_ITEMS];
	stringArr = new std::string*[MAX_ITEMS];
	//stringArr.resize(MAX_ITEMS);
	for (int i = 0; i < MAX_ITEMS; i++) {
		stringArr[i] = NULL;
	}


	size = 0;
	x = _x;
	y = _y;

	//index
	index = 0;
	lastIndex = 0;

	//size
	height = 12;
	width = _width;

	//padding and spacing
	spacing = 10;
	topPadding = 10;
	bottomPadding = 10;
	leftPadding = 10;
	rightPadding = 10;

	//colors
	backgroundColor = sf::Color(47, 79, 79, 255);
	fontColor = sf::Color::White;
	selectedFontColor = sf::Color::Red;

	//font
	fontSize = 18;
	font.loadFromFile("./assets/font.ttf");
	layer->add(background);

	//background
	background.setPosition(x, y);
	background.setFillColor(backgroundColor);

	//timer
	updateTimer.start();
	updateRate = 200;
}

//DECONSTRUCTOR
Menu::~Menu() {
	delete[] textArr;
}

//ADD
void Menu::add(std::string& text) {
	stringArr[size] = &text;
	textArr[size].setString(text);
	textArr[size].setFont(font);
	textArr[size].setPosition(sf::Vector2f(x + leftPadding, y + topPadding + (size * (height + spacing))));
	textArr[size].setFillColor(fontColor);
	textArr[size].setCharacterSize(fontSize);
	layer->add(textArr[size]);
	size++;

	if (size == 1)
		indexChange(0);
}

//ADD LITERAL
void Menu::addLiteral(std::string text) {
	textArr[size].setFont(font);
	textArr[size].setString(text);
	textArr[size].setPosition(sf::Vector2f(x + leftPadding, y + topPadding + (size * (height + spacing))));
	textArr[size].setFillColor(fontColor);
	textArr[size].setCharacterSize(fontSize);
	layer->add(textArr[size]);
	size++;

	if (size == 1)
		indexChange(0);
}

//ADD LITERAL W/ V_ARGS
void Menu::addLiteral(int n_items, ...) {
	/*va_list vl;
	va_start(vl, n_items);

	for (int i = 0; i<n_items; i++)
	{
		std::string text = va_arg(vl, std::string);
		textArr[size].setFont(font);
		textArr[size].setString(text);
		textArr[size].setPosition(sf::Vector2f(x + leftPadding, y + topPadding + (size * (height + spacing))));
		textArr[size].setFillColor(fontColor);
		textArr[size].setCharacterSize(fontSize);
		layer->add(textArr[size]);
		size++;

		if (size == 1)
			indexChange(0);
	}

	va_end(vl);*/
}


//NEXT
void Menu::next() {
	lastIndex = index;
	index == size-1 ? index = 0 : index++;
	indexChange(index);
}

//PREV
void Menu::prev() {
	lastIndex = index;
	index <= 0 ? index = size-1 : index--;
	indexChange(index);
}

//SELECT
void Menu::indexChange(int select) {
	textArr[lastIndex].setFillColor(fontColor);
	textArr[select].setFillColor(selectedFontColor);
}

//SELECTED
unsigned int Menu::selected() {
	return index;
}


//RESHAPE
void Menu::reshape() {
	unsigned int longestLine = 0;
	for (int i = 0; i < size; i++) {
		textArr[i].getString().getSize() > longestLine ? longestLine = textArr[i].getString().getSize() : longestLine;
	}

	width = longestLine * 10;

	background.setSize(sf::Vector2f(width + leftPadding + rightPadding, (height + spacing)*size + topPadding + bottomPadding));
}

//UPDATE
void Menu::update() {
	if(updateTimer.getMilliseconds() > updateRate)
	for (int i = 0; i < size; i++)
		if (stringArr[i] != NULL) {
			textArr[i].setString(*stringArr[i]);
			updateTimer.reset();
		}
}

//SET POSITION
void Menu::setPosition(float _x, float _y) {
	x = _x;
	y = _y;
}

//SET FONT COLOR
void Menu::setFontColor(sf::Color color) {
	fontColor = color;
}

//SET SELECTED FONT COLOR
void Menu::setSelectedFontColot(sf::Color color) {
	selectedFontColor = color;
}

//SET BACKGROUND COLOR
void Menu::setBackgroundColor(sf::Color color) {
	backgroundColor = color;
}

//SET SIZE
void Menu::setSize(float _height, float _width) {
	height = _height;
	width = _width;
}

//SET PADDING
void Menu::setPadding(float top, float bottom, float left, float right) {
	topPadding = top;
	bottomPadding = bottom;
	leftPadding = left;
	rightPadding = right;
}

//SET SPACING
void Menu::setSpacing(float _spacing) {
	spacing = spacing;
}

//SET UPDATE RATE
void Menu::setUpdateRate(unsigned int _updateRate) {
	updateRate = _updateRate;
}