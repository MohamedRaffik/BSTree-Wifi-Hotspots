
template <class T>
Node<T>::Node(T & new_data)
{
	data = new_data;
	right_node = NULL;
	left_node = NULL;
}


template <class T>
BST<T>::BST() {}


template <class T>
BTree<T>::BTree()
{
	head_node = NULL;
	size = 0;
}



template <class T>
int BTree<T>::insert(T & data)
{
    Node<T> * new_node = new Node<T>(data);

    if (new_node == NULL) { return 0; }

    if (head_node == NULL)
    {
		head_node = new_node;
		size++;
		return 1;
    }

    else
    {
		Node<T> * current = head_node;

        while (current != NULL)
		{
            if (current->data < new_node->data)
            {
                if (current->right_node == NULL) { current->right_node = new_node; size++; return 1; }

                else { current = current->right_node; }
            }

            else if (new_node->data < current->data)
            {
				if (current->left_node == NULL) { current->left_node = new_node; size++; return 1; }

				else { current = current->left_node; }
            }

            else { break; }
		}
    }

    return 0;

}



template <class T>
int BTree<T>::remove(const T & data)
{
	Node<T> * current = head_node;
	Node<T> * parent = NULL;

    while (current != NULL)
    {
        if (data < current->data) { parent = current; current = current->left_node; }

        else if (current->data < data) { parent = current; current = current->right_node; }

        else { break; }
    }

    if (current == NULL) { return 0; }

    if ((current->right_node == NULL) && (current->left_node == NULL))
    {
        if (parent == NULL) { head_node = NULL; }

        else if (parent->left_node == current) { parent->left_node = NULL; }

        else if (parent->right_node == current) { parent->right_node = NULL; }

        delete current;
        current = NULL;
        size--;
        return 1;
    }

    else if ((current->right_node == NULL) || (current->left_node == NULL))
    {
        if (current->right_node == NULL)
        {
            if (parent == NULL) { head_node = current->left_node; }

            else if (parent->right_node == current) { parent->right_node = current->left_node; }

            else if (parent->left_node == current) { parent->left_node = current->left_node; }
        }

        else if (current->left_node == NULL)
        {
            if (parent == NULL) { head_node = current->right_node; }

            else if (parent->right_node == current) { parent->right_node = current->right_node; }

            else if (parent->left_node == current) { parent->left_node = current->right_node; }
        }

        delete current;
        current = NULL;
        size--;
        return 1;
    }

    else
    {
        Node<T> * successor;
        Node<T> * parent_of_successor;

        successor = current->right_node;
        parent_of_successor = current;

        while (successor->left_node != NULL)
        {
            parent_of_successor = successor;
            successor = successor->left_node;
        }

        current->data = successor->data;

        if (successor->right_node != NULL)
        {
            if (parent_of_successor->left_node == successor) { parent_of_successor->left_node = successor->right_node; }

            else if (parent_of_successor->right_node == successor) { parent_of_successor->right_node = successor->right_node; }
        }

        else
        {
            if (parent_of_successor->left_node == successor) { parent_of_successor->left_node = NULL; }

            else if (parent_of_successor->right_node == successor) { parent_of_successor->right_node = NULL; }
        }

        delete successor;
        successor = NULL;
        size--;
        return 1;
    }

	return 0;
}



template <class T>
T BTree<T>::retrieve(const T & data)
{
	Node<T> * current = head_node;

	while (current != NULL)
	{
		if (current->data < data) { current = current->right_node; }

		else if (data < current->data) { current = current->left_node; }

		else { break; }
	}

	return current->data;
}



template <class T>
int BTree<T>::make_empty()
{
	int items = 0;

	stack<Node<T>*> parents;

	Node<T> * current = head_node;
	Node<T> * extra;

    while (current != NULL)
    {
        parents.push(current);
        current = current->left_node;
    }

    while (!parents.empty())
    {
		extra = parents.top();
		current = extra->right_node;

		delete extra;
		extra = NULL;
		size--;
		items++;

		parents.pop();

		while (current != NULL)
		{
			parents.push(current);
			current = current->left_node;
		}
    }

    return items;
}



template <class T>
T BTree<T>::get_smallest()
{
	Node<T> * current = head_node;

	while (current->left_node != NULL) { current = current->left_node; }

	return current->data;
}



template <class T>
void BTree<T>::print(ostream & s)
{
	stack<Node<T>*> parents;

    Node<T> * current = head_node;

    while (current != NULL)
    {
		parents.push(current);
		current = current->left_node;
    }

    while (!parents.empty())
    {
		current = parents.top();
		s << current->data;
		current = current->right_node;

		parents.pop();

        while (current != NULL)
        {
			parents.push(current);
			current = current->left_node;
        }
    }
}


template <class T>
int BTree<T>::length()
{
	return size;
}


template <class T>
int BTree<T>::merge(BTree new_tree)
{
    int items = 0;

    while (new_tree.length() != 0)
    {
		T temp = new_tree.get_smallest();
        insert(temp);
        new_tree.remove(temp);
        items++;
    }

    return items;
}
