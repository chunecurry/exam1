enter the command: sudo mbed compile --source . --source ~/ee2405/mbed-os-build/ -m B_L4S5I_IOT01A -t GCC_ARM -f
push the button (A1 is used to decrease the pre_freq, A3 is used to increase the pre_freq)(note that each change is 10 frequencies.)
push the A2 to confirm the frequency of the wave (then the /dev/ttyACM* will output the sampled data)
enter the command: sudo python3 FFT.py
the code FFT.py will output a figure which has two subplots

![螢幕擷取畫面 2021-04-07 170003](https://user-images.githubusercontent.com/75109528/113849592-3f890900-97cc-11eb-8f31-63d70f2530c2.png)
when input is 1

![螢幕擷取畫面 2021-04-07 170058](https://user-images.githubusercontent.com/75109528/113849716-59c2e700-97cc-11eb-93d5-3538a43f2164.png)
when input is 1/2

![螢幕擷取畫面 2021-04-07 182442](https://user-images.githubusercontent.com/75109528/113851964-98f23780-97ce-11eb-9d88-41e093797bb4.png)
when input is 1/4

![螢幕擷取畫面 2021-04-07 181247](https://user-images.githubusercontent.com/75109528/113850286-e2da1e00-97cc-11eb-8df7-fbf89234dec0.png)
when input is 1/8

![螢幕擷取畫面 2021-04-07 180441](https://user-images.githubusercontent.com/75109528/113850340-eec5e000-97cc-11eb-8a3d-3d6c01d26f34.png)
FFT when input is 1
