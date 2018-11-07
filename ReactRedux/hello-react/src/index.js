/*
import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import Header from './header';
import Content from './content';
import Footer from './footer';
import {Router,Route,Link,browserHistory} from 'react-router'

ReactDOM.render(
	<Router history={browserHistory}>
		<Route path="/" component={App} />
		<Route path="/header" component={Header} />
		<Route path="/content" component={Content} />
		<Route path="/footer" component={Footer} />
	</Router>,document.getElementById('root')
);
*/



import {createStore} from "redux";
const reducer=(state,action) =>{
	switch (action.type) {
		case "ADD":
			state += action.payload;
			break;
		case "SUBTRACT":
			state -= action.payload;
			break;
		default:
	}
	return state;
};

const store=createStore(reducer,15000);
store.subscribe(() =>{
	console.log("Update Store : ", store.getState());
})

store.dispatch({
	type:"ADD",
	payload:500
});

store.dispatch({
	type:"SUBTRACT",
	payload:10000
});