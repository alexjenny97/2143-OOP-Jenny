## Instructions

### For Machine Setup:

Run the following:

```sh
# make installer executable
chmod +x install.sh 

# run the installer
# if uses sudo, so when prompted for password, enter it.
./install.sh

# make your compile command executable
chmod +x compile
```

### After Setup:

- Edit your `whatever.cpp` like normal
- The `compile` command needs an `input file` and an `output object file`
- So to compile your project run: `./compile whatever.cpp executable_name`
- To run your project: `./executable_name` 
