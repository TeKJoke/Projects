from sys import argv


def main():
    if len(argv) == 2:
        cmd = argv[1]
        print(f'My task . {cmd}')
    else:
        e0 = '404 invalid input'
        print(f"ERROR {e0}")

if __name__ == '__main__':
    main()
