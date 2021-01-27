FROM node:14

WORKDIR /usr/src/app
COPY package*.json ./
RUN npm install

#Debugport mapping
EXPOSE 9229

COPY rover*.js ./

CMD [ "npm", "run", "test" ]
