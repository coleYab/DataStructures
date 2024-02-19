#include <string>
#include <iostream>

using namespace std;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    string str;
    struct list_s *next;
} list_t;


int print_list(const list_t *h)
{
    int length = 0;

    while (h)
    {
        cout << "["<< h->str.length() << " ]   "  << h->str << endl;
        h = h->next, length += 1;
    }

    return length;
}

int count_len(const list_t *h)
{
    int length = 0;

    while (h)
        h = h->next, length += 1;

    return length;
}

list_t *add_node(list_t **head, const string str)
{
    list_t *temp = new list_t;

    if (!temp)
        return nullptr;
    temp->str = str;
    temp->next = *head;
    *head = temp;

    return *head;
}

list_t *add_node_end(list_t **head, const string str)
{
    list_t *temp = *head;

    if (*head == nullptr)
        return add_node(head, str);
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->next = new list_t;
        temp = temp->next;
        temp->str = str;
        temp->next = nullptr;
    }

    return temp;
}

void free_list(list_t *head)
{
    list_t *temp = head;

    while (head->next)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    delete temp;
    head = nullptr;
}

string pop_listint(list_t **head)
{
    string popped_value = "[Nill]";
    list_t *temp;

    if (head && *head)
    {
        temp = *head;
        popped_value = temp->str;
        *head = temp->next;
        delete temp;
    }

    return popped_value;
}


list_t *get_nodeint_at_index(list_t *head, int index)
{
    int length = 0;
    list_t *temp = head;

    while (length != index && temp)
    {
        temp = temp->next, length += 1;
    }

    return temp;
}

list_t *insert_nodeint_at_index(list_t **head, int index, string name)
{
    bool is_inserted {false};
    list_t *temp {*head};
    int length = 0;

    while (temp && length != index - 1)
    {
        length += 1;
        temp = temp->next;
    }
    if (length == index - 1)
    {
        list_t *temp2 = new list_t;
        temp2->str = name;
        temp2->next = temp->next;
        temp->next = temp2;
    }
    else
        temp = nullptr;
    return temp;
}
