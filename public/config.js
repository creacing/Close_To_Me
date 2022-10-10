import avator from './../public/images/avator.jpg'
const author = 'Cheshire Cat'
const config = {
    author,
    title: '柴郡猫',
    description: 'Wonderland',
    nav: [
        { name: author, link: "/", children: [], liClass: 'title', rel: 'start', iClass: '', aClass: '' },
        { name: '首页', link: "/", children: [], liClass: '', rel: 'section', iClass: 'i-home', aClass: '' },
        { name: '归档', link: "/archives/", children: [], liClass: '', rel: 'section', iClass: 'i-list-alt', aClass: '' },
        { name: '标签', link: "/tags", children: [], liClass: '', rel: 'section', iClass: 'i-tags', aClass: '' },
        { name: '收藏', link: "/WebSites/", children: [], liClass: '', rel: 'section', iClass: 'i-star', aClass: '' },
        { name: '关于', link: "/about/", children: [], liClass: '', rel: 'section', iClass: 'i-cloud', aClass: '' },
        { name: 'Github', link: "#", children: [], liClass: '', rel: 'noopener external nofollow noreferrer', iClass: 'i-paper-plane', aClass: 'exturl' }
    ],
    sidebar: {
        avator,
        description: '一个专注于前端的web爱好者',
        articlesNum: '0',
        categoriesNum: '0',
        tagsNum: '33',
        socialLinks: [
            { url: 'https://github.com/', name: 'github', icon: "i-github" },
            { url: 'https://twitter.com/', name: 'twitter', icon: "i-twitter" },
            { url: 'https://www.zhihu.com/people/', name: 'zhihu', icon: "i-zhihu" },
            { url: 'https://music.163.com/', name: 'music', icon: "i-cloud-music" },
            { url: 'https://t.me/', name: 'telegram', icon: "i-paper-plane" },
        ]
    },
    //colud color
    cloudColorList: [
        '#747bff',
        '#646cff',
        '#cf9baa',
        '#de8293',
        '#5b93b1',
        '#1b5489',
        '#7690b8',
        '#cfd8e0',
        '#6896b7',
        '#db8ea6',
        '#7b9361',
        '#3b6f87',
        '#b85b6c',
        '#dd8a94',
        '#f38b61',
        '#ffa842',
        '#596085',
        '#3e3a64',
        '#e15195',
        '#5fa3d5',
        '#7c94b1',
        '#3e749f',
        '#da7b35',
        '#ff9d4e',
        '#345a6d',
    ]
}
export default config