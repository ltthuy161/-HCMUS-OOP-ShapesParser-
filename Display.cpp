#include "Display.h"


/// <summary>
/// In thong tin co ban cua danh sach cac hinh
/// </summary>
/// <param name="shapes">vector chua danh sach cac hinh</param>
void DisplayBasicInfor::display(vector<shared_ptr<Shape>> shapes) {
    for (int i = 0; i < shapes.size(); i++) {
        cout << i + 1 << ". " << shapes[i]->getShapeType() << ": ";  
        shapes[i]->display(); 
        cout << endl;
    }
}

/// <summary>
/// In thong tin co ban kem chu vi dien tich cua tung hinh 
// Chu vi lam tron 1 chu thap phan, dien tich lam tron 2 chu so thap phan
/// </summary>
/// <param name="shapes">vector chua danh sach cac hinh</param>
void  DisplayFullInfor::display(vector<shared_ptr<Shape>> shapes) {
    for (int i = 0; i < shapes.size(); ++i) {
        cout << "| " << left << setw(2) << i + 1 << " | "
            << left << setw(15) << shapes[i]->getShapeType() << " | ";  
        
        cout <<  "Perimeter=" << setw(6) << fixed << setprecision(1) << shapes[i]->perimeter() << " | "
            << "Area=" << setw(6) << fixed << setprecision(2) << shapes[i]->area() << " |" << endl;
    }
}


DisplayListShape::DisplayListShape(shared_ptr<DisplayStrategy> dpShape) {
    _displayShapes = dpShape;
}

void DisplayListShape::setTypeDisplay(shared_ptr<DisplayStrategy>dpShape) {
    this->_displayShapes = dpShape;
}

void DisplayListShape::performTypeOfDisplay(vector<shared_ptr<Shape>> shapes) {
    _displayShapes->display(shapes);
}