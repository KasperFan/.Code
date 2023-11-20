from tqdm import tqdm
from time import sleep

# for i in tqdm(range(20)):
#     sleep(0.5)

seconds: int = 20

for seconds in tqdm(range(20, 0, -1), desc=f"等待时间", ):
    sleep(0.97)
tqdm.close(self)
