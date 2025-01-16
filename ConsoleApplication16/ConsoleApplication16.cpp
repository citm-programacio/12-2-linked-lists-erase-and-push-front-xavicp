// ConsoleApplication16.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

// Estructura de Nodo para un Árbol de Búsqueda Binaria (BST)
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Función para crear un nuevo Nodo
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Función para insertar un nodo en el BST
Node* insertNode(Node* root, int data)
{
    if (root == nullptr) { // Si el árbol está vacío, retorna un nuevo nodo
        return createNode(data);
    }

    // De lo contrario, recorre el árbol
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // Retorna el puntero al nodo (sin cambios)
    return root;
}

// Función para buscar un nodo en el BST
Node* searchNode(Node* root, int key)
{
    if (root == nullptr || root->data == key) {
        return root; // Nodo encontrado o árbol vacío
    }

    if (key < root->data) {
        return searchNode(root->left, key);
    }

    return searchNode(root->right, key);
}

// Función para encontrar el nodo con el valor mínimo en el BST
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Función para eliminar un nodo en el BST
Node* erase(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = erase(root->left, key);
    }
    else if (key > root->data) {
        root->right = erase(root->right, key);
    }
    else {
        // Nodo encontrado
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Nodo con dos hijos
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = erase(root->right, temp->data);
    }

    return root;
}

// Función para insertar un nodo en la raíz del BST (push_front simulado)
Node* pushFront(Node* root, int data) {
    Node* newNode = createNode(data);

    if (root == nullptr) {
        return newNode;
    }

    newNode->left = root;
    return newNode;
}

void printTreeStructure(Node* node, int indent = 0, char prefix = 'R') {
    if (node == nullptr) return;

    // Imprimir el subárbol derecho primero (de arriba hacia abajo)
    if (node->right) {
        printTreeStructure(node->right, indent + 4, 'R');
    }

    // Imprimir el nodo actual
    if (indent > 0) {
        for (int i = 0; i < indent - 4; i++) {
            cout << ".";
        }
        cout << (prefix == 'R' ? "----" : "----");
    }
    cout << node->data << endl;

    // Imprimir el subárbol izquierdo
    if (node->left) {
        printTreeStructure(node->left, indent + 4, 'L');
    }
}

// Función principal para demostrar las operaciones del BST
int main()
{
    Node* root = nullptr;
    // Crear un BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 35);
    root = insertNode(root, 80);

    // Imprimir la estructura del árbol
    cout << "Estructura del Árbol de Búsqueda Binaria: " << endl;
    printTreeStructure(root);
    cout << endl;

    // Buscar un nodo en el BST
    Node* found = searchNode(root, 25);
    if (found != nullptr) {
        cout << "Nodo 25 encontrado en el BST." << endl;
    }
    else {
        cout << "Nodo 25 no encontrado en el BST." << endl;
    }

    // Eliminar un nodo en el BST
    cout << "Eliminando el nodo 30..." << endl;
    root = erase(root, 30);
    printTreeStructure(root);

    // Insertar un nodo en la raíz
    cout << "Insertando 10 en la raíz..." << endl;
    root = pushFront(root, 10);
    printTreeStructure(root);

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
