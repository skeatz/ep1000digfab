
## EP1000

### How to make a website using Jake Wright's template

1.  Watch the Youtube Video Jake Wright: [Learn CSS in 12 minutes](https://youtu.be/0afZj1G0BIE).
2.  Draw out the plan for your website, suggest that you use the one provided by Jake Wright.
3.  Code your website
    * Create a new folder for the site
    * Create the home page, name it `index.html`.
    * Create the style sheet, save it in the same folder. Name the style sheet `style.css`
    * Test your webpage, by opening `index.html` on your browser.
4.  Modify the CSS file to suit your liking.
5.  Original version of Jake's work for demo -[JakeWright-OriginalCode.zip](JakeWright-OriginalCode.zip)

![Webpage using HTML and CSS](index_html.png)

&nbsp;

### How to add pages to your website

We are going to add an **About** page to the above website.  The About page will have an image and text, but retain the same navigational-look-and-feel of the website.

We will create a **docs** folder in which we will keep the `about.html` and the image file `user.jpg`.  The following diagram shows the structure (hierachy) of the files on the system.

![Website file structure](site_layout.jpg)

1. Create the folder `docs` on the site.
2. We will need to modify `index.html` to accomodate the links to the other pages that we might want to add e.g. About, ProjectManagement, WebsiteDevelopment, 3Dprinting, 2Dcutting etc.  it is best that you add in these links as placeholders for your site.
3. Edit the navigation section of `index.html`.  The code below shows how we can add placeholders for future work.  We will assume that these pages will be stored in the `docs` folder.

    ```html
        <div id="nav">
        <h3>Navigation</h3>
        <ul>
            <li><a href="" class="selected">Home</a></li>
            <li><a href="docs/safety.html">Safety</a></li>
            <li><a href="">Website Dev</a></li>
            <li><a href="prj/project.html">Project</a></li>
            <li><a href="docs/about.html">About</a></li>
        </ul>
        </div>
    ```

4. **index.html** on the root of the website   
    **docs/about.html** is in the folder docs on the root   
    **prj/project.html** is in the folder prj on the root   
    In this way, we can map the relative locations of the different web pages we wish to host on this site.   
    The ***disadvantage*** of this method of usin HTML and CSS and having a Navigation page, is that should the navigtion section of main file `index.html` change, you will need to **edit** and change each and every one of the files.


5. Make a copy of `index.html` and save it in the `docs` folder  as **about.html**.  The index file acts as a template for all other pages that follow.

6. Edit the contents of `about.html` to reflect the position of the file and change the navigation section.

    ```html
        <div id="nav">
            <h3>Navigation</h3>
            <ul>
                <li><a href="../index.html" >Home</a></li>
                <li><a href="safety.html">Safety</a></li>
                <li><a href="">Website Dev</a></li>
                <li><a href="../prj/project.html">Project</a></li>
                <li><a href="about.html" class="selected">About</a></li>
            </ul>
        </div>
    ```

7. Note the changes to the locations of the links:
    * **../index.html** means to go-up-one-folder to reach the home page
    * **../prj/project.html** means to go up one folder and then down the `prj`folder to find the file 'project.html`

8. Any files referenced directly from the `about.html` file would mean that the file is also located in the same folder.

9. Change the contents of the **main div** as this holds the contents of the page.

10.  You can test the website [here](index.html).


&nbsp;

**May 2020**