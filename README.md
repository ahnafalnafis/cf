# `cf`

`cf` short for "Create file" is a cli tool to create files.

## Features and limitations

For now it can only create files. Although it doesn't support GNU like argument
parsing, it supports globbing. Since it was only tested on **Bash**, globbing
may not work on other shells.

Though unix-like operating system's have `touch`, `touch` it's limitation is it
can only create files in current directory and other directories if those are
already created. But this is where `cf` shines, you can tell it to create
missing directories along with the file name.

For example, if you want to create `bar.txt` in `foo` directory, if `foo` was
created in `touch` you'd run `touch foo/bar.txt`. But if `foo` doesn't exist
you will get an error that says the directory `foo` is missing. But in `cf`,
if `foo` doesn't exist, it'll create `foo` for you and then `bar.txt`.

It's one and only purpose in life is to create files for you. So it doesn't
support other features of `touch`.
