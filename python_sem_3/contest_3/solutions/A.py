import sys


class ToStdout:
    pass


class ToStderr:
    pass


class ToDevnull:
    pass


class stream_switcher:
    def __init__(self, stdout=ToStdout, stderr=ToStderr):
        user_stdout, user_stderr = None, None
        if stdout.__name__ == "ToStdout":
            user_stdout = sys.stdout
        elif stdout.__name__ == "ToStderr":
            user_stdout = sys.stderr
        if stderr.__name__ == "ToStdout":
            user_stderr = sys.stdout
        elif stderr.__name__ == "ToStderr":
            user_stderr = sys.stderr
        sys.stdout, sys.stderr = user_stdout, user_stderr

    def __enter__(self):
        pass

    def __exit__(self, *args):
        sys.stdout, sys.stderr = sys.__stdout__, sys.__stderr__
