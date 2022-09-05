<template>
  <!-- affix -->
  <div id="sidebar">
    <div class="inner">
      <div class="panels">
        <div class="inner">
          <div class="contents panel pjax" data-title="文章目录"></div>
          <div class="related panel pjax" data-title="系列文章"></div>
          <div class="overview panel active" data-title="站点概览">
            <div class="author" itemprop="author" itemscope itemtype="http://schema.org/Person">
              <img
                class="image lozaded"
                itemprop="image"
                alt="Ruri Shimotsuki"
                data-src="//cdn.jsdelivr.net/gh/amehime/shoka@30732f13/images/avatar.jpg"
                src="//cdn.jsdelivr.net/gh/amehime/shoka@30732f13/images/avatar.jpg"
                data-loaded="true"
              />
              <p class="name" itemprop="name">Ruri Shimotsuki</p>
              <div class="description" itemprop="description">琉璃的医学 &amp; 编程笔记</div>
            </div>
            <nav class="state">
              <div class="item posts">
                <a href="/archives/" data-pjax-state>
                  <span class="count">216</span>
                  <span class="name">文章</span>
                </a>
              </div>
              <div class="item categories">
                <a href="/categories/" data-pjax-state>
                  <span class="count">48</span>
                  <span class="name">分类</span>
                </a>
              </div>
              <div class="item tags">
                <a href="/tags/" data-pjax-state>
                  <span class="count">71</span>
                  <span class="name">标签</span>
                </a>
              </div>
            </nav>
            <div class="social">
              <a
                href="https://github.com/amehime"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item github"
                title="https://github.com/amehime"
              >
                <i class="ic i-github"></i>
              </a>
              <a
                href="https://twitter.com/amehime"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item twitter"
                title="https://twitter.com/amehime"
              >
                <i class="ic i-twitter"></i>
              </a>
              <a
                href="https://www.zhihu.com/people/amehime"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item zhihu"
                title="https://www.zhihu.com/people/amehime"
              >
                <i class="ic i-zhihu"></i>
              </a>
              <a
                href="https://music.163.com/#/user/home?id=12886823"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item music"
                title="https://music.163.com/#/user/home?id=12886823"
              >
                <i class="ic i-cloud-music"></i>
              </a>
              <a
                href="https://t.me/amehime"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item telegram"
                title="https://t.me/amehime"
              >
                <i class="ic i-paper-plane"></i>
              </a>
              <a
                href="https://about.me/amehime"
                rel="noopener external nofollow noreferrer"
                target="_blank"
                class="exturl item about"
                title="https://about.me/amehime"
              >
                <i class="ic i-address-card"></i>
              </a>
            </div>
            <ul class="menu">
              <li class="item active">
                <a href="/" rel="section" data-pjax-state>
                  <i class="ic i-home"></i>首页
                </a>
              </li>
              <li class="item dropdown">
                <a href="/about/" rel="section" data-pjax-state>
                  <i class="ic i-user"></i>关于
                </a>
                <ul class="submenu">
                  <li class="item">
                    <a href="/about/yume" rel="section" data-pjax-state>
                      <i class="ic i-cloud"></i>自设
                    </a>
                  </li>
                </ul>
              </li>
              <li class="item dropdown">
                <a href="javascript:void(0);" data-pjax-state>
                  <i class="ic i-feather"></i>文章
                </a>
                <ul class="submenu">
                  <li class="item">
                    <a href="/archives/" rel="section" data-pjax-state>
                      <i class="ic i-list-alt"></i>归档
                    </a>
                  </li>
                  <li class="item">
                    <a href="/categories/" rel="section" data-pjax-state>
                      <i class="ic i-th"></i>分类
                    </a>
                  </li>
                  <li class="item">
                    <a href="/tags/" rel="section" data-pjax-state>
                      <i class="ic i-tags"></i>标签
                    </a>
                  </li>
                </ul>
              </li>
              <li class="item dropdown">
                <a href="javascript:void(0);" data-pjax-state>
                  <i class="ic i-magic"></i>链环
                </a>
                <ul class="submenu">
                  <li class="item">
                    <a href="/friends/" rel="section" data-pjax-state>
                      <i class="ic i-heart"></i>友達
                    </a>
                  </li>
                  <li class="item">
                    <a href="/webstack/" rel="section" data-pjax-state>
                      <i class="ic i-star"></i>网址
                    </a>
                  </li>
                </ul>
              </li>
              <li class="item">
                <a
                  href="https://travellings.link"
                  rel="noopener external nofollow noreferrer"
                  target="_blank"
                  class="exturl"
                  title="开往"
                >
                  <i class="ic i-paper-plane"></i>开往
                </a>
              </li>
            </ul>
          </div>
        </div>
      </div>
      <ul id="quick">
        <li class="prev pjax"></li>
        <li class="up">
          <i class="ic i-arrow-up"></i>
        </li>
        <li class="down">
          <i class="ic i-arrow-down"></i>
        </li>
        <li class="next pjax">
          <a href="/page/2/" rel="next" title="下一篇" data-pjax-state>
            <i class="ic i-chevron-right"></i>
          </a>
        </li>
        <li class="percent" style="width: 16%;"></li>
      </ul>
    </div>
  </div>
</template>
<script setup>
import { onMounted, ref } from 'vue'
import config from "../../public/config";
const { sidebar } = config
const fixSidebar = ref(false)
onMounted(() => {
})
</script>

<style lang='scss' scoped>
.panels {
  padding-top: 0.625rem;
}
#sidebar {
  position: sticky;
}
</style>