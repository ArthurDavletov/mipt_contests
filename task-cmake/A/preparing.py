def create_header():
    with open("task-cmake/A/index.h", "w", encoding="utf-8") as file:
        header_body = """\
#ifndef INDEX_H
#define INDEX_H

// Что тут написать, я не знаю, помогите

#endif
"""
        file.write(header_body)


if __name__ == "__main__":
    create_header()
