function insertArticle(titlu,continut)
{ 
	var articole=document.getElementsByClassName("articole")[0];
	var page=document.getElementsByClassName("page")[0];
	var primary=document.createElement("div");
	primary.className="primary-col";
	var generic=document.createElement("div");
	generic.className="generic";
	var panel=document.createElement("div");
	panel.className="panel";
	var title=document.createElement("div");
	title.className="title";

    var header_titlu=document.createElement("h1");
    header_titlu.appendChild(document.createTextNode(titlu));
    title.appendChild(header_titlu);
    panel.appendChild(title);

    var content=document.createElement("div");
    var p_content=document.createElement("p");
    var buton=document.createElement("div");
    buton.className="button mar-top20";
    buton.innerHTML="<a href='#'>More INfo</a>";
    content.className="content";
    p_content.appendChild(document.createTextNode(continut));
    content.appendChild(p_content);
    content.appendChild(buton);
    panel.appendChild(content);

    var margine=document.createElement("div");
    margine.className="mar-bottom20";

    generic.appendChild(panel);
	generic.appendChild(margine);
	primary.appendChild(generic);
	articole.appendChild(primary);
	page.appendChild(articole);
}

window.onload=function(){insertArticle("titlu  1", "continut 1");insertArticle("titlu 2", "continut 2");};




