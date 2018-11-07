import React, { Component } from 'react';

class Header extends Component{
	constructor(){
		super();
		this.state={
			name:"Unlike",
			count:0
		};
	}
  render (){
    var mystyle = {
      fontSize : 50,
      color : '#00FF00'
    };

/*
    setTimeout(()=> {
    	this.setState({name:"Like"});
    	},2000);
    setInterval(()=> {
    	this.setState({count:this.state.count+1 });
    	},500);
*/

    return(
        <div>
          <h1 style={mystyle}> My Header </h1>
          <h2> {this.state.name} </h2>
          <h2> {this.state.count} </h2>

          <h1><a href="/">Home</a></h1>
        </div>  
      );
  }
}


export default Header;