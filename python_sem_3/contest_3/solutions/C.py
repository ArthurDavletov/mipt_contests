from functools import wraps


def logger_decorator(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        if isinstance(func, classmethod):
            answer = func.__func__(eval(func.__qualname__.split('.')[0]), *args, **kwargs)
            print(f"Function name: {func.__qualname__}")
        else:
            answer = func(*args, **kwargs)
            print(f"Function name: {func.__name__}")
        if args and func.__name__ in dir(args[0]):
            method = getattr(args[0], func.__name__)
            if func == method.__wrapped__:
                args = args[1:]
        if "self" in kwargs:
            del kwargs["self"]
        if "cls" in kwargs:
            del kwargs["cls"]
        print(f"Arguments: {args} {kwargs}")
        print(f"Return value: {answer}")
        return answer
    return wrapper
