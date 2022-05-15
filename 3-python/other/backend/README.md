### Install dependencies
```shell
pip install -r requirements.txt
```

### Run server
```shell
uvicorn main:app --reload --port 8080
```

### Docker
```shell
docker build -t fastapi .
docker run -p 8080:80 fastapi
``` 

### Api
```shell
http://127.0.0.1:8080/get_weather
```