#README
<h1>CS100 - Homework 1: rshell - Writing a Basic Command Shell</h1>
<p>In this project, we are building a student made command shell using C++ source code. It takes in a string of commands and connectors from the user that will be executed in the shell.</p> 

<h2>RShell Features</h2>
<p>The commands are parsed so that they are separated into their command and argument lists. The program looks for connectors while ignoring anything after a "#".</p>

<p>Once the commands are successfully parsed, then the commands will be executed. If the command is successfully executed, then the command will behave as intended. However, if it does not succeed, then the command will result in an error message.</p>

<p>This shell also allows for the use of the connectors <strong><em>;</em></strong>, <strong><em>&&</em></strong>, and <strong><em>||</em></strong>.</p> 
<ul>
    <li><strong><em>;</em></strong> - the following command is executed regardless of the status of the previous command.</li>
    <li><strong><em>&&</em></strong> - the following command is executed only if the previous command succeeds.</li>
    <li><strong><em>||</em></strong> - the following command is executed only if the previous command fails.</li>
</ul>

<h2>Known Bugs</h2>
<ul>

</ul>
