#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  int priority;
  Element *next;
  Element(T data, int priority){
    this -> data = data;
    this -> priority = priority;
    this -> next = nullptr;
  }
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T>head;
  ElementPtr<T>tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T>newqueue;
  newqueue.head = nullptr;
  newqueue.tail = nullptr;
  return newqueue;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T>newqueue = new Element<T>(value, priority);
  if(q.head == nullptr){
    q.head = newqueue;
    q.tail = newqueue;
  } else {
    ElementPtr<T>helptr = q.head;
    ElementPtr<T>helptr2 = nullptr;
    while(helptr->priority >= priority&& helptr->next != nullptr){
      helptr2 = helptr;
      helptr = helptr->next;
    }

    if (helptr == q.head && helptr->priority <priority){
      newqueue->next = helptr;
      q.head = newqueue;
    }

    else if (helptr == q.tail && helptr->priority > priority){
      helptr->next = newqueue;
      q.tail = newqueue;
    }

    else {
      helptr2->next = newqueue;
      newqueue->next = helptr;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T>deleteqhead;
  if (q.head == nullptr && q.tail == nullptr){
    deleteqhead = nullptr;
  }

  else if (q.head->next == nullptr){
    deleteqhead = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } 

  else {
    deleteqhead = q.head;
    q.head = q.head->next;
    deleteqhead->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
